git config --global --replace-all hooks.clangformat.style google
cd ..
git clone https://github.com/andrewseidl/githook-clang-format.git
cp githook-clang-format/clang-format.hook proxy/.git/hooks/pre-commit
