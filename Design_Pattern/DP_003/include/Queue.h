#ifndef QUEUE_H_
 
#define QUEUE_H_
 
#define QUEUE_SIZE 10
/* class Queue */
typedef struct Queue Queue;
struct Queue {
    int buffer[QUEUE_SIZE]; /* where the data things are */
    int head;   //Chỉ số đầu của hàng đợi, nơi thêm phần tử mới
    int size;   //Số lượng phần tử hiện tại trong hàng đợi
    int tail;   //Chỉ số cuối của hàng đợi, nơi phần tử bị loại bỏ

    //<kiểu_trả_về> (*<tên_con_trỏ>)(<danh_sách_tham_số>);
    int (*isFull)(Queue* const me);     //Con ttro hàm để kiểm tra hàng đợi có đầy không
    int (*isEmpty)(Queue* const me);    //Con trỏ hàm để kiểm tra hàng đợi có trống không
    int (*getSize)(Queue* const me);    //Con trỏ lấy kích thước của hàng đợi
    void (*insert)(Queue* const me, int k); //Con trỏ hàm chèn phần tử vào hàng đợi
    int (*remove)(Queue* const me); //Con trỏ hàm xóa phần tử khỏi hàng đợi
};
/* Constructors and destructors:*/
void Queue_Init(Queue* const me,int (*isFullfunction)(Queue* const me),
                                int (*isEmptyfunction)(Queue* const me),
                                int (*getSizefunction)(Queue* const me),
                                void (*insertfunction)(Queue* const me, int k),
                                int (*removefunction)(Queue* const me));
void Queue_Cleanup(Queue* const me);
/* Operations */
 
int Queue_isFull(Queue* const me);
 
int Queue_isEmpty(Queue* const me);
 
int Queue_getSize(Queue* const me);
 
void Queue_insert(Queue* const me, int k);
 
int Queue_remove(Queue* const me);
 
Queue * Queue_Create(void);
 
void Queue_Destroy(Queue* const me);
 
#endif /*QUEUE_H_*/