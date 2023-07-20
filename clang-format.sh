git config --global --replace-all hooks.clangformat.style google
cd ..
git clone https://github.com/andrewseidl/githook-clang-format.git
cp githook-clang-format/clang-format.hook proxy/.git/hooks/pre-commit


# #!/bin/bash

# STYLE=$(git config --get hooks.clangformat.style)
# if [ -n "${STYLE}" ] ; then
#     STYLEARG="-style=${STYLE}"
# else
#     # try source root dir
#     STYLE=$(git rev-parse --show-toplevel)/.clang-format
#     if [ -n "${STYLE}" ] ; then
#         STYLEARG="-style=file"
#     else
#         STYLEARG=""
#     fi
# fi

# format_file() {
#     file="${1}"
#     if [ ! -z "${STYLEARG}" ]; then
#         #echo "format ${file}"
#         clang-format -i ${STYLEARG} ${1}
#         git add ${1}
#     fi
# }

# # 注意这里对格式化的文件做了限制，test文件目录下的文件不格式化，另外非.cpp/.h的文件不格式化，可自行修改
# is_need_format() {
#     need=1
#     file=$1

#     // ignore /test/*
#     if [[ "${file}" == */test/* ]]; then
#         need=0
#     fi

#     if [[ $need -eq 1 ]]; then
#         # only c/c++ source file
#         if [ x"${file##*.}" != x"cpp" -a x"${file##*.}" != x"h" ]; then
#             #echo "not cpp source"
#             need=0
#         fi
#     fi

#     return $need
# }

# case "${1}" in
#     --about )
#         echo "Runs clang-format on source files"
#         ;;
#     * )
#         for file in `git diff-index --cached --name-only HEAD` ; do
#             is_need_format ${file}
#             if [[ $? -eq 1 ]]; then
#                 format_file "${file}"
#             fi
#         done
#         ;;
# esac
