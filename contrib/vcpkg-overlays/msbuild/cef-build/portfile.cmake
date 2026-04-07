set(orig_VCPKG_LIBRARY_LINKAGE ${VCPKG_LIBRARY_LINKAGE})

set(CEF_VERSION "96.0.16")
set(CHROMIUM_VERSION "96.0.4664.55")
set(PLATFORM_NAME "windows32")
set(COMMIT_SHORTHASH "89c902b")
set(ARCHIVE_HASH "568be01f229b07266dc3bf7920036a9e7ae0096870dca4ab80c091338c66e54d147e6e6864c470c6f8c024188c9c763915e5614c41fcbbb6c17565e11e2b7dc9")

set(FOLDER_NAME "cef_binary_${CEF_VERSION}+g${COMMIT_SHORTHASH}+chromium-${CHROMIUM_VERSION}_${PLATFORM_NAME}")
set(ARCHIVE_NAME "${FOLDER_NAME}.tar.bz2")

vcpkg_download_distfile(
	ARCHIVE
	URLS "https://cef-builds.spotifycdn.com/${ARCHIVE_NAME}"
	FILENAME "${ARCHIVE_NAME}"
	SHA512 ${ARCHIVE_HASH}
)

vcpkg_extract_source_archive_ex(
	OUT_SOURCE_PATH SOURCE_PATH
	ARCHIVE "${ARCHIVE}"
	REF "${CEF_VERSION}"
	PATCHES
		"patch-cmake.patch"
)

# Required, or else libcef.lib gives the error "Could not find proper second linker member." Chromium does the same: https://github.com/microsoft/vcpkg/blob/030cfaa24de9ea1bbf0a4d9c615ce7312ba77af1/ports/chromium-base/portfile.cmake
set(VCPKG_POLICY_SKIP_ARCHITECTURE_CHECK enabled)

# Required, or else we get "outdated crt" errors when copying some pre-built DLLs.
set(VCPKG_POLICY_SKIP_DUMPBIN_CHECKS enabled)

# Required, or else you get linker errors
set(VCPKG_LIBRARY_LINKAGE static)

# Disable PREFER_NINJA because it changes the output directories slightly
# TODO: Try adding it back

set(CEF_CONFIG_OPTS -DUSE_SANDBOX=NO)
if("${VCPKG_CRT_LINKAGE}" STREQUAL "dynamic")
	list(APPEND CEF_CONFIG_OPTS -DCEF_RUNTIME_LIBRARY_FLAG=/MD)
endif()

vcpkg_configure_cmake(
	SOURCE_PATH "${SOURCE_PATH}"
	OPTIONS ${CEF_CONFIG_OPTS}
)

set(VCPKG_LIBRARY_LINKAGE ${orig_VCPKG_LIBRARY_LINKAGE})

# TODO: Try vcpkg_copy_pdbs
vcpkg_install_cmake()

set(RELEASE_BUILD_DIR "${CURRENT_BUILDTREES_DIR}/${HOST_TRIPLET}-rel")
set(DEBUG_BUILD_DIR "${CURRENT_BUILDTREES_DIR}/${HOST_TRIPLET}-dbg")

#########################################

# /copyright
file(
	INSTALL "${SOURCE_PATH}/LICENSE.txt"
	DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}"
	RENAME copyright)

# duplicate include
file(REMOVE_RECURSE ${CURRENT_PACKAGES_DIR}/debug/include)

#if(VCPKG_LIBRARY_LINKAGE STREQUAL "static")
#    file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/bin" "${CURRENT_PACKAGES_DIR}/debug/bin")
#endif()