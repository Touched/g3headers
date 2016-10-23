#!/usr/bin/env python3

import yaml
import sys
import os.path

def singleton_dict(d):
    return next(iter(d.items()))


def type_to_directive(t):
    if t not in ('long', 'short', 'byte'):
        raise ValueError(t)

    return t


def generate_argument_enum(name, attr, prefix):
    lines = []
    for n, v in map(singleton_dict, attr['values']):
        key = '{}_{}'.format(name.upper(), n.upper())
        lines.append('.equ {}{}, {}'.format(prefix, key, v))

    return ('byte', lines)


def generate_command_macro(command, prefix='', index_size=4):
    if len(command) != 1:
        raise ValueError

    name, attr = singleton_dict(command)

    # Extra a list of argument names
    arguments = attr.get('arguments', [])
    argument_names = map(lambda x: singleton_dict(x)[0], arguments)

    lines = [
        '.macro {}{} {}'.format(prefix, name.upper(), ', '.join(argument_names)),
        '.byte 0x{:02x}'.format(attr['index'])
    ]
    indent = ' ' * index_size
    defs = []

    for name, argument in map(singleton_dict, arguments):
        if (argument['type'] == 'enum'):
            directive, definition = generate_argument_enum(name, argument, prefix)
            defs.append(definition)
        else:
            directive = type_to_directive(argument['type'])

        lines.append('.{} \{}'.format(directive, name))


    lines.append('.endm')
    for definition in defs:
        lines.append('')
        lines += definition

    return indent + ('\n' + indent).join(lines)


def main():
    inp = os.path.abspath(sys.argv[1])
    outp = os.path.abspath(sys.argv[2])

    with open(inp) as istream, open(outp, 'w') as ostream:
        data = yaml.load(istream, Loader=yaml.Loader)

        for command in data['commands']:
            prefix = data['prefix'].upper()
            item = generate_command_macro(command, prefix=prefix)
            print(item , end='\n\n', file=ostream)

if __name__ == '__main__':
    main()
