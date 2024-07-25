# tests/meson.build
test_dependencies = []

# Add Catch2 dependency
catch2_dep = subproject('catch2').get_variable('catch2_with_main_dep')
test_dependencies += catch2_dep

test_args = []
test_link_args = []
test_overrides = ['warning_level=3']

test_source_files = files('matrix_vec.cpp')

test_exe = executable(
    meson.project_name() + '_tests',
    test_source_files,
    cpp_args: test_args,
    link_args: test_link_args,
    dependencies: test_dependencies,
    override_options: test_overrides,
    include_directories: include_directories('../include')  # Ensure headers are found
)

test(meson.project_name() + '_tests', test_exe)