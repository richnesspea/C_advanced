#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h> // Thư viện hỗ trợ dynamic loading

int main() {
    // Tải thư viện động
    void *handle = dlopen("./shared_library.so", RTLD_LAZY);
    if (!handle) {
        printf("Failed to load library: %s\n", dlerror()); // Lấy lỗi chi tiết
        return -1;
    }

    // Lấy con trỏ đến hàm trong thư viện
    void (*shared_function)() = dlsym(handle, "shared_library_function");
    if (!shared_function) {
        printf("Failed to find symbol: %s\n", dlerror());
        dlclose(handle);
        return -1;
    }

    // Gọi hàm từ thư viện
    shared_function();

    // Đóng thư viện động
    dlclose(handle);

    return 0;
}
