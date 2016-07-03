set -e

REPO_PATH="https://github.com/Touched/PokeAGB.git"
HTML_PATH=doc/html
COMMIT_USER="Travis CI"
COMMIT_EMAIL="travis@travis-ci.org"

rm -rf $HTML_PATH
mkdir -p $HTML_PATH
git clone -b gh-pages "${REPO_PATH}" --single-branch $HTML_PATH

cd $HTML_PATH
git rm -rf .
touch .nojekyll
cd ..

make

cd html
git add .
git config user.name $COMMIT_USER
git config user.email $COMMIT_EMAIL
git commit -m "Deploy code docs to GitHub Pages Travis build: ${TRAVIS_BUILD_NUMBER}" \
    -m "Commit: ${TRAVIS_COMMIT}"
git push -f -q "https://Touched:$GITHUB_API_KEY@github.com/Touched/PokeAGB.git" gh-pages
