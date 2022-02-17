class IOWrapper {
private:
    handle_t handle;
public:
    IOWrapper() = delete;
    IOWrapper(IOWrapper const &han_new) = delete;
    IOWrapper& operator=(IOWrapper const &han_new) = delete;
    //IOWrapper(handle_t handle): handle(handle) { };
    //IOWrapper(handle_t &&handle): handle(handle) { };

    IOWrapper(IOWrapper&& here): handle(here.handle) {
        here.handle = kNullHandle;
    }

    IOWrapper(const handle_t &han_new){
        handle = han_new;
    }

    IOWrapper(handle_t &&han_new) {
        handle = std::move(han_new);
    }

    IOWrapper& operator=(IOWrapper &&han_new) {
        handle = han_new.handle;
        han_new.handle = kNullHandle;
    }

    ~IOWrapper() {
        if (handle != kNullHandle) {
            raw_close(handle);
        }
    }

    void Write (const std::string& content){
        if (handle != kNullHandle) {
            raw_write(handle, content);
        }
    }
};
