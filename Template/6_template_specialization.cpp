template <typename T> //Primary template
struct PTS {
    enum {
       IsPointer = 0,
       IsPointerToDataMember = 0
    };
 };

template <typename T> //// Partial specialization for T as a pointer
struct PTS<T*> {
    enum {
       IsPointer = 1,
       IsPointerToDataMember = 0
    };
 };

 struct S{};