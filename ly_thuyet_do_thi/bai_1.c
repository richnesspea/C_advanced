#include <stdio.h>

/*
    I. Các khái niệm cơ bản về lí thuyết đồ thị
        1. Đơn đồ thị vô hướng
            * G = <V, E> 
                - G: graph
                - V: vertices/ nodes: các đỉnh của đồ thị
                - E: edges: các cạnh của đồ thị
            * Giữa 2 nodes chỉ có 1 edge
            * giữa 2 nodes không có hướng
        2. Đa đồ thị vô hướng
            * Giữa 2 nodes có nhiều edges
        3. Giả đồ thị vô hướng (ít dùng)
            * Edge bắt đầu từ 1 node và quay về chính node đó  -> Cạnh khuyên
            * Còn lại thì giống đa đồ thị vô hướng
        4. Đơn đồ thị có hướng
            * Các cạnh có thứ tự -> cung
        5. Đa đồ thị có hướng 
        6. Đỉnh kề và cạnh liên thuộc
        7. Bậc của đỉnh trên đồ thị vô hướng: deg(u)
            * Số cạnh liên thuộc của đỉnh đó
            * Chỉ áp dụng với đồ thị vô hướng
            * Đồ thị vô hướng m cạnh thì tổng bậc của đỉnh = 2 * m
        8. Bán bậc của đỉnh trên đồ thị có hướng:
            * Bán bậc ra: deg+(u)
            * Bán bậc vào: deg-(u)
            * <3, 0>: 
              - 3: số lượng bán bậc ra
              - 0: số lượng bán bậc vào 
            * Tổng bán bậc ra = tổng bán bậc vào = số cạnh m

*/

int main(){

}