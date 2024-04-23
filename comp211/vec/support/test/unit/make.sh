#!/bin/bash

script_dir=$(dirname "$(realpath "${0}")")
project_dir=$(realpath "$script_dir/../../..")
build_dir="${project_dir}/build/test/unit"
unit_tests_dir="${project_dir}/test/unit"

main() {
    if [ "${0}" == "-bash" ]; then
        echo "Must be run as a script."
        return
    else
        init
        sync_cmake
        run_make "$@"
    fi
}

init() {
    # Create test build directory
    if [ ! -d "${build_dir}" ]; then
        mkdir -p "${build_dir}" || exit 1
    fi

    # Link CMake files in
    if [ ! -f "${build_dir}/CMakeLists.txt" ]; then
        ln -s "${script_dir}/CMakeLists.txt" "${build_dir}/" || exit 1
    fi

    if [ ! -f "${build_dir}/GoogleTestLists.txt.in" ]; then
        ln -s "${script_dir}/GoogleTestLists.txt.in" "${build_dir}/" || exit 1
    fi

    # Symbolically link project dirs into build directory
    link_dirs="test include src"
    for dir in $link_dirs; do
        source_dir="${project_dir}/${dir}"
        link_dir="${build_dir}/${dir}"
        if [ ! -d "${link_dir}" ]; then
            ln -s "${source_dir}" "${link_dir}" || exit 1
        fi
    done
}

sync_cmake() {
    test_makefile="${build_dir}/Makefile"
    tests=$(ls "$unit_tests_dir")

    if [ -f "${test_makefile}" ]; then
        rebuild="false"
        # Test for files in unit tests that are not in Makefile
        for test_file in $tests; do
            if ! grep -q "${test_file}" "${test_makefile}"; then
                echo "${test_file}"
                rebuild="true"
            fi
        done

        # Test for files in Makefile that are no longer in unit tests dir
        grep_re="\\.PHONY : \\(test/unit/.\\+\\.cpp\\)\\.o"
        sed_cmd='s/.PHONY : \(.*\).o/\1/'
        files_makefile=$(grep "${grep_re}" "${test_makefile}" | sed "${sed_cmd}")
        for file_makefile in $files_makefile; do
            if [ ! -f "${project_dir}/${file_makefile}" ]; then
                echo "${project_dir}/${file_makefile}"
                rebuild="true"
            fi
        done
    else
        # CMake needs to be run for the first time
        rebuild="true"
    fi

    if [ "${rebuild}" = "true" ]; then
        cd "${build_dir}" || exit 1
        cmake . || exit 1
    fi
}

run_make() {
    cd "${build_dir}" || exit 1
    make "$@" || exit 1
}

main
