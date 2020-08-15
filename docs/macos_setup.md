# MacOS 开发环境配置

- 使用 vs code + vcpkg 为主要工具

# vcpkg 配置

- 详见：https://github.com/Microsoft/vcpkg#installing-macos-developer-tools
- 摘要：
    1. 需要安装 xcode: "xcode-select --install"
    1. 需要在 settings.json 中配置 “CMAKE_TOOLCHAIN_FILE” 为本机的 vcpkg.cmake 路径