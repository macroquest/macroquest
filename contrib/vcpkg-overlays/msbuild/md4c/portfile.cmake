vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO mity/md4c
    REF release-0.4.8
    SHA512 c939fdadf3e05c32c570cf9a5c0a02f83afaf4dfacf0f4505fcf12c6e24ffe0cd1372c207ff47cf2a489b02f24c5f20bb5f1361453c847c5464225cc7fcdb5ab
)

vcpkg_configure_cmake(
    SOURCE_PATH ${SOURCE_PATH}
)

vcpkg_install_cmake()

vcpkg_fixup_cmake_targets(CONFIG_PATH "lib/cmake/md4c")

vcpkg_copy_pdbs()

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/share")

if(VCPKG_LIBRARY_LINKAGE STREQUAL "static")
    file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/bin" "${CURRENT_PACKAGES_DIR}/debug/bin")
endif()

file(INSTALL ${SOURCE_PATH}/LICENSE.md DESTINATION ${CURRENT_PACKAGES_DIR}/share/${PORT} RENAME copyright)
