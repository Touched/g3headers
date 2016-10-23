#!/usr/bin/env python3

from xml.etree import ElementTree
import os.path
import glob
import functools
import itertools

ROOT = 'doc/xml/'
OUTPUT_ROOT = 'build/linker/'

@functools.lru_cache(maxsize=None)
def load_xml_file(path):
    tree = ElementTree.parse(path)
    return tree.getroot()


def load_member(file_refid, member_refid):
    root = load_xml_file(os.path.join(ROOT, file_refid + '.xml'))
    return root.find(".//memberdef[@id='{}']".format(member_refid))


def load_by_ref_id(refid):
    root = load_xml_file(os.path.join(ROOT, 'index.xml'))
    compound = root.find(".//member[@refid='{}']..".format(refid))
    return load_member(compound.attrib['refid'], refid)


def build_entry(member):
    address = next(
        filter(
            lambda el: el.attrib['id'].startswith('address'),
            member.findall('.//xrefsect')
        )
    )

    kind = member.attrib['kind']

    if kind not in ['function', 'variable']:
        raise RuntimeError('Cannot have address for a ' + kind)

    return {
        'name': member.find('name').text,
        'file': member.find('location').attrib['file'],
        'kind': kind,
        'defintion': member.find('definition').text,
        'address': int(address.find('xrefdescription/para').text.strip(), 16)
    }


def write_entry(entry):
    thumb = entry['kind'] == 'function'
    return '{name} = 0x{address:08x}{extra};'.format(extra='|1' if thumb else '', **entry)


def load_addresses(filename):
    root = load_xml_file(filename)

    # Extract the version code string
    version = root.find('compounddef').attrib['id'].split('address')[-1]

    # Build up a list of entries
    xpath = ".//ref[@kindref='member']"
    entries = [build_entry(load_by_ref_id(ref.attrib['refid'])) for ref in root.findall(xpath)]

    # Write a linker script
    output_path = os.path.join(OUTPUT_ROOT, version + '.ld')
    print('Generating linker script `{}` from `{}` ({} entries)'.format(
        output_path,
        filename,
        len(entries)
    ))

    with open(output_path, 'a') as output:
        keyfn = lambda x: x['file']
        for filename, group in itertools.groupby(sorted(entries, key=keyfn), keyfn):
            print('/*\n * {}\n */\n'.format(filename), file=output)

            for entry in group:
                print(write_entry(entry), file=output)

            print(file=output)


for filename in glob.glob(os.path.join(ROOT, 'address*.xml')):
    load_addresses(filename)
