# NguyenDucDuong_202514083
# Week 4 homework: Hanoi Tower

---

## 1. Giới thiệu bài toán

* **Mục tiêu:** Di chuyển $n$ đĩa kích thước khác nhau từ cọc nguồn (`A`) sang cọc đích (`C`), sử dụng cọc tạm thời (`B`) làm trung gian.
* **Quy tắc:**
  * Mỗi lần chỉ di chuyển 1 đĩa nằm ở trên cùng của một cọc.
  * Không được đặt đĩa lớn hơn lên trên đĩa nhỏ hơn.
* **Số bước tối ưu:** $2^n - 1$ bước.

---

## 2. Phương pháp 1: Cài đặt bằng Đệ quy (Recursive)

### 2.1. Ý tưởng giải thuật
Để chuyển $n$ đĩa từ `source` sang `target` qua `temp`:
* **Base case ($n = 1$):** Chuyển trực tiếp đĩa 1 từ `source` sang `target`.
* **Recursive step ($n > 1$):**
  1. Chuyển $n - 1$ đĩa từ `source` sang `temp` (mượn `target`).
  2. Chuyển đĩa thứ $n$ từ `source` sang `target`.
  3. Chuyển $n - 1$ đĩa từ `temp` sang `target` (mượn `source`).

### 2.2. Độ phức tạp
* **Thời gian (Time Complexity):** $O(2^n)$
* **Không gian (Space Complexity):** $O(n)$ (Call Stack)

---

## 3. Phương pháp 2: Khử Đệ quy bằng Stack (Non-Recursive)

### 3.1. Ý tưởng giải thuật
Sử dụng cấu trúc dữ liệu `Stack` tự quản lý để mô phỏng lại Call Stack của hệ điều hành:

```c
typedef struct {
    int n;          // Số lượng đĩa
    char source;    // Cọc nguồn
    char target;    // Cọc đích
    char temp;      // Cọc trung gian
} Task;
```
### 3.2. Cơ chế đảo ngược thứ tự đẩy vào Stack (LIFO)
Do Stack hoạt động theo nguyên lý LIFO (Last In, First Out — vào sau ra trước), khi phân rã một bài toán lớn ($n > 1$), các công việc con cần được đẩy vào Stack theo thứ tự ngược lại so với trình tự thực thi:

* **Đẩy công việc bước 3 vào trước:**  
  `Task task3 = {current.n - 1, current.temp, current.target, current.source};`  
  *(Chuyển $n - 1$ đĩa từ `temp` sang `target` mượn `source` làm trung gian)*
* **Đẩy công việc bước 2 vào giữa:**  
  `Task task2 = {1, current.source, current.target, current.temp};`  
  *(Chuyển đĩa thứ $n$ từ `source` sang `target`)*
* **Đẩy công việc bước 1 vào cuối cùng:**  
  `Task task1 = {current.n - 1, current.source, current.temp, current.target};`  
  *(Chuyển $n - 1$ đĩa từ `source` sang `temp` mượn `target` làm trung gian để được lấy ra xử lý ngay ở vòng lặp kế tiếp)*

Vòng lặp tiếp tục lấy từng `Task` ra khỏi Stack xử lý cho đến khi Stack rỗng hoàn toàn.

### 3.3. Đánh giá độ phức tạp
* **Thời gian (Time Complexity):** $O(2^n)$ (thực hiện tối ưu đúng $2^n - 1$ thao tác).
* **Không gian (Space Complexity):** $O(n)$ (kích thước tối đa của cấu trúc Stack tương đương độ sâu đệ quy lớn nhất).

---

## 4. Test Cases kiểm thử giải thuật

Cả hai thuật toán (Đệ quy và Khử đệ quy bằng Stack) đều sinh chuỗi thao tác đồng nhất:

### Test Case 1: $n = 1$
* **Input:** $n = 1$, Nguồn: A, Đích: C, Trung gian: B
* **Output:**
  ```text
  Move disk from A to C
  ```
### Test Case 2: $n = 2$
* **Input:** $n = 2$, Nguồn: A, Đích: C, Trung gian: B
* **Output:**
  ```text
  Move disk from A to B
  Move disk from A to C
  Move disk from B to C
  ```
### Test Case 3: $n = 3$
* **Input:** $n = 3$, Nguồn: A, Đích: C, Trung gian: B
* **Output:**
  ```text
  Move disk from A to C
  Move disk from A to B
  Move disk from C to B
  Move disk from A to C
  Move disk from B to A
  Move disk from B to C
  Move disk from A to C
  ```

