# LeetCode 韌體面試準備筆記

這份檔案是給未來跨裝置開發時快速接上狀態用的。主要目標不是把題目刷爆，而是把 LeetCode 練習整理成「韌體工程師面試」會用得到的 C/C++ 基礎、資料結構與解題手感。

## 目標

- 準備韌體工程師面試。
- 用 LeetCode 補強 C/C++ 基礎、指標與記憶體、資料結構、常見面試題型。
- 練習時優先用 C；需要物件導向或 STL 思路時再用 C++。
- 每題不只求 AC，也要能在面試時說清楚：
  - 題目核心技巧
  - 時間與空間複雜度
  - C 語言容易踩到的地方
  - 邊界條件

## 個人背景摘要

履歷主軸偏嵌入式與車聯網安全通訊：

- C/C++、CMake、Git、交叉編譯。
- Embedded Linux、Yocto/BitBake、ARMv7。
- FreeRTOS、MCU、CAN、Timer、ADC、PWM、PID。
- 密碼學與安全通訊：ECC、BLS、Hash Tree、聚合驗證。
- 專案經驗包含 Embedded-SecLink、OBU 去中心化通訊系統、EVPI 電動車資安感測平台。

所以 LeetCode 的準備方向要和這些背景接起來：位元操作、記憶體管理、資料結構實作、低階字串處理、穩定的 C 寫法，會比很偏競賽的難題更重要。

## Repo 現況

- 目前分成 `Easy`、`Medium`、`Hard`、`Common`。
- 主力語言是 C，少量 C++ 和 Python。
- 目前檔案數大約是：
  - `.c`: 58
  - `.cpp`: 15
  - `.py`: 2
  - `.json`: 1
- 各資料夾目前檔案數：
  - `.vscode`: 1
  - `Common`: 6
  - `Easy`: 29
  - `Medium`: 39
  - `Hard`: 1
- 目前 git 狀態：
  - branch: `master...origin/master`
  - 2026-05-17 檢查時，已新增 CAN encode/decode 與 linked list 面試題整理，準備提交並推送。
  - 上一個已推提交：`2925377 Practice bit manipulation review set`。
  - 本機 `rg` 目前可正常使用。

## 已觀察到的題型基礎

目前 repo 已經有不少和韌體面試相關的題型：

- 位元操作：
  - `136 Single Number`
  - `137 Single Number II`
  - `190 Reverse Bits`
  - `191 Number of 1 Bits`
  - `231 Power of Two`
  - `268 Missing Number`
  - `371 Sum of Two Integers`
- 鏈結串列：
  - `141 Linked List Cycle`
  - `142 Linked List Cycle II`
  - `206 Reverse Linked List`
  - `21 Merge Two Sorted Lists`
  - `19 Remove Nth Node From End of List`
- Stack / Queue：
  - `20 Valid Parentheses`
  - `232 Implement Queue using Stacks`
  - `739 Daily Temperatures`
- 常見資料結構：
  - `146 LRU Cache`
  - `641 Design Circular Deque`
  - `Common/Circular_Buffer.c`
  - `Common/LRU_Cache.c`
  - `Common/CAN_encoder.c`
- 搜尋與陣列：
  - `704 Binary Search`
  - `33 Search in Rotated Sorted Array`
  - `34 Find First and Last Position`
  - `209 Minimum Size Subarray Sum`
  - `167 Two Sum II`
- 圖與 BFS/DFS：
  - `200 Number of Islands`
  - `207 Course Schedule`
  - `994 Rotting Oranges`

後續重點不是從零開始，而是把這些題目重刷、整理筆記，並補上韌體面試高頻但 repo 還沒有的題目。

## 韌體面試優先順序

1. 位元操作
2. 指標與記憶體
3. C 字串與陣列
4. 鏈結串列
5. Stack / Queue / Circular Buffer
6. Binary Search、Two Pointers、Sliding Window
7. Tree / Graph 基本 DFS、BFS
8. Dynamic Programming

DP 和比較競賽感的難題不是完全不碰，但 4 週衝刺時不要讓它們壓過 C 基礎與韌體常見資料結構。

## C 與嵌入式口試清單

參考筆記：https://hackmd.io/@Chienyu/S1loEqCuo

這份 HackMD 很適合當成韌體面試前的 C 語言口試題庫。它的重點不是 LeetCode 題目，而是面試官很常用來確認你是不是真的熟 C 與嵌入式限制。

優先整理這些主題：

- Preprocessor / macro：
  - `#define` 常數與巨集。
  - 巨集參數要加括號。
  - `MIN(a, b)` 這類巨集的副作用，例如 `MIN(*p++, b)`。
  - `#error` 可用來在編譯期擋錯誤設定。
- 型別、宣告與指標：
  - `int *a`、`int **a`、`int a[10]`、`int (*a)[10]`。
  - 函式指標與函式指標陣列。
  - `typedef` 和 `#define` 定義指標型別的差異。
- `static` / `const` / `volatile`：
  - `static` 在函式內、檔案內變數、檔案內函式的差異。
  - `const int *p`、`int * const p`、`const int * const p`。
  - `volatile` 用在硬體暫存器、ISR 共享變數、多工共享變數。
  - `volatile` 不等於 thread-safe，也不等於 memory barrier。
- 位元操作與硬體暫存器：
  - set / clear / toggle / check bit。
  - 用 `1U << n` 避免 signed shift 問題。
  - 絕對位址轉指標，例如 memory-mapped register。
- 中斷與嵌入式限制：
  - ISR 不回傳值、不帶一般參數。
  - ISR 內避免 `printf`、浮點運算、太長的流程。
  - ISR 只做短工作，重工作交給 main loop 或 task。
- C 常見陷阱：
  - signed / unsigned 混用造成比較結果錯誤。
  - `~0` 比寫死 `0xFFFF` 更不依賴字長。
  - `a+++b` 會被解析成 `a++ + b`。
  - heap allocation 在嵌入式可能造成碎片、生命週期不好控。

建議做法：

- 每週從上面挑 5 到 8 題，用自己的話寫成短答。
- 每個主題至少補一個 C 小範例放在 `Common`。
- 面試前要能不用背稿講出原因，尤其是 `volatile`、macro 副作用、ISR 限制、signed/unsigned。

## Linux kernel 學習建議

以你的履歷來看，可以接觸 Linux kernel，但不需要一開始就讀完整核心。比較聰明的路線是先學「driver 觀念」與「user space / kernel space 邊界」，這會直接接到 Embedded Linux、Yocto、OBU、驅動整合這些履歷內容。

建議優先順序：

1. Linux 基礎操作與系統觀念：
   - process / thread
   - virtual memory
   - file descriptor
   - syscall
   - `/proc`、`/sys`
   - permission、device node
2. Kernel module 入門：
   - hello module
   - `init` / `exit`
   - `printk`
   - `insmod` / `rmmod` / `lsmod` / `dmesg`
3. Character device driver：
   - `open` / `read` / `write` / `release`
   - major / minor number
   - `copy_to_user` / `copy_from_user`
   - blocking / non-blocking 基本概念
4. Driver model 基礎：
   - device / driver / bus
   - platform device / platform driver
   - device tree 只先懂用途，不急著深挖語法細節
5. 和韌體面試連結：
   - interrupt bottom half 概念
   - workqueue / tasklet 先知道用途
   - memory allocation：`kmalloc`、`kzalloc`
   - concurrency：spinlock、mutex 的使用情境

暫時不用先碰太深：

- scheduler 細節
- memory manager 內部
- network stack 深層實作
- 大量讀 kernel source
- 真的送 upstream patch

4 週衝刺期間，Linux kernel 建議當作加分線：每週 1 到 2 小時就好。先做出一個簡單 character device driver，比硬讀核心架構更有面試價值。

## 額外支線：linux-kernel-driver-demo

這是一條獨立於 LeetCode 的實作支線，目標是做出一個小而完整、能放上 GitHub 與履歷的 Linux kernel / BSP 學習專案。

Project name:

- `linux-kernel-driver-demo`

Target platform:

- Raspberry Pi running Linux.

主要目標：

- 建立一個實用的 Linux kernel driver demo。
- 可用於 Junior BSP、BMC、Embedded Linux、Platform Firmware 相關職缺作品集。
- 重點是可編譯、可測試、可解釋，不追求複雜功能。

明確不要一開始就做：

- Yocto image building
- U-Boot porting
- PCIe
- camera / display
- 進階 kernel internals

這條支線要學到：

1. Linux kernel module basics
2. character device driver
3. user-space to kernel-space communication
4. ioctl
5. basic Device Tree / platform driver
6. optional GPIO interrupt handling

預期 repository 結構：

```text
linux-kernel-driver-demo/
├── README.md
├── Makefile
├── include/
│   └── walker_ioctl.h
├── driver/
│   ├── hello_module.c
│   ├── walker_chrdev.c
│   └── walker_platform.c
├── user/
│   └── user_test.c
├── dts/
│   └── walker-gpio-demo-overlay.dts
└── docs/
    ├── architecture.md
    ├── user_kernel_flow.md
    └── test_log.md
```

### Phase 0：Hello Kernel Module

先建立最小 kernel module。

需要完成：

- `driver/hello_module.c`
- module load 時用 `pr_info` 印出訊息。
- module remove 時用 `pr_info` 印出訊息。
- 提供 `Makefile`。
- `README.md` 要包含並解釋：
  - `make`
  - `sudo insmod hello_module.ko`
  - `dmesg`
  - `lsmod`
  - `sudo rmmod hello_module`

README 要說清楚：

- kernel module 是什麼。
- `insmod` 和 `rmmod` 做什麼。
- `dmesg` 用來看什麼。

### Phase 1：Character Device Driver

建立 `/dev/walker_demo` 字元裝置。

檔案：

- `driver/walker_chrdev.c`

需求：

- 使用 `alloc_chrdev_region`。
- 使用 `cdev_init` 和 `cdev_add`。
- 使用 `class_create` 和 `device_create` 建立 `/dev/walker_demo`。
- 實作 `file_operations`：
  - `open`
  - `release`
  - `read`
  - `write`
- 維護一個 kernel internal buffer。
- 使用者可以：
  - `echo "hello" > /dev/walker_demo`
  - `cat /dev/walker_demo`
- 正確使用 `copy_to_user` 和 `copy_from_user`。
- 加上合理錯誤處理。
- 重要 kernel API 要有清楚註解。

README 要說清楚：

- major number
- minor number
- `cdev`
- `file_operations`
- `copy_to_user`
- `copy_from_user`
- 為什麼 user space 不能直接存取 kernel memory。

Phase 0 和 Phase 1 做完後要先停下來，等 Raspberry Pi 實機測試結果，再繼續 Phase 2。

### Phase 2：ioctl Support

等 Phase 0 / Phase 1 測試通過後再做。

共享標頭：

- `include/walker_ioctl.h`

需求：

- 定義 ioctl commands：
  - `WALKER_IOCTL_RESET`
  - `WALKER_IOCTL_GET_BUFFER_SIZE`
  - `WALKER_IOCTL_SET_MODE`
- 使用 `_IO`、`_IOR`、`_IOW`。
- 在 driver 實作 `unlocked_ioctl`。
- `RESET` 清空 kernel buffer。
- `GET_BUFFER_SIZE` 回傳目前 buffer size。
- `SET_MODE` 儲存一個簡單整數 mode。
- 建立 `user/user_test.c` 測試 open、write、read、RESET、GET_BUFFER_SIZE、SET_MODE。

README 要說清楚：

- ioctl 是什麼。
- 什麼情境下 ioctl 比 read/write 適合。
- user-space C program 如何和 kernel driver 溝通。

### Phase 3：Platform Driver + Device Tree

檔案：

- `driver/walker_platform.c`
- `dts/walker-gpio-demo-overlay.dts`

需求：

- 實作 `platform_driver`。
- 加上 `of_device_id` table。
- compatible string 使用 `"walker,gpio-demo"`。
- 實作 `probe` 和 `remove`。
- `probe` 印出 device matched。
- `remove` 印出 device removed。
- 提供 Raspberry Pi Device Tree overlay 範例。

README 要說清楚：

- Device Tree 是什麼。
- compatible string 的用途。
- `probe` 和 `remove` 做什麼。
- 為什麼 BSP engineer 需要懂 Device Tree。

### Phase 4：Optional GPIO Interrupt

只有 Phase 0 到 Phase 3 都完成並測過後才做。

需求：

- 從 Device Tree 取得 GPIO。
- 將 GPIO 轉成 IRQ。
- 註冊 interrupt handler。
- interrupt handler 只做最少工作。
- 使用 workqueue 或 wait queue 做 deferred processing。
- user space 可從 `/dev/walker_demo` 讀取簡單 event。

README 要說清楚：

- interrupt context
- workqueue
- wait queue
- 為什麼 interrupt handler 不能做 heavy work，也不能 sleep。

### Phase 5：Documentation for Resume and Interview

建立文件：

- `docs/architecture.md`
- `docs/user_kernel_flow.md`
- `docs/test_log.md`

`architecture.md` 要說明：

- project architecture
- user-space app flow
- kernel driver flow
- read/write/ioctl flow
- Device Tree binding flow

`user_kernel_flow.md` 要說明：

- user space vs kernel space
- system call path 概念
- read/write/ioctl 如何到達 `file_operations`
- 為什麼需要 `copy_to_user` / `copy_from_user`

`test_log.md` 要記錄範例命令與預期輸出：

- `make`
- `insmod`
- `dmesg`
- `lsmod`
- `echo` / `cat /dev/walker_demo`
- `user_test`
- `rmmod`

### README 必放內容

README 第一段固定使用這個方向：

> This project is a Linux kernel driver learning project implemented on Raspberry Pi. It demonstrates character device driver development, user-kernel communication through read/write/ioctl, basic platform driver binding with Device Tree, and optional GPIO interrupt handling. The goal is to build practical foundations for Junior BSP, BMC, Embedded Linux, and Platform Firmware roles.

README 也要包含履歷 bullet points：

- Linux Kernel Driver Demo on Raspberry Pi
- Implemented a Linux character device driver with open/read/write/ioctl interfaces.
- Developed a user-space C test program to communicate with the kernel module through `/dev` device node.
- Practiced kernel module loading, `dmesg` debugging, and user-kernel space data transfer.
- Extended the project with basic Device Tree and platform driver binding concepts.
- Optionally implemented GPIO interrupt handling with deferred processing.

### 支線 coding rules

- Kernel code 使用 C，不用 C++。
- 註解清楚，但不要過度包裝。
- 每個 phase 都要能獨立工作，再進下一個 phase。
- 正確性與清楚度優先於炫技。
- 不假設特定 kernel version；遇到 API 版本差異要註明相容性考量。
- 盡量避免 deprecated API。
- README 要解釋重要命令與 kernel API。

### 支線進度紀錄規則

- 每次開始或結束這條支線的工作，都要更新本檔案的「學習紀錄」。
- 紀錄要包含日期時間、做了什麼、測了什麼、目前卡點、下一步。
- 如果使用者回報 Raspberry Pi 測試結果，也要整理進「學習紀錄」。
- Phase 0 和 Phase 1 完成後必須等待實機測試結果，不要直接往 Phase 2 做。

## 4 週衝刺路線

### 第 1 週：C 基礎與位元操作

重刷：

- `136 Single Number`
- `137 Single Number II`
- `190 Reverse Bits`
- `191 Number of 1 Bits`
- `231 Power of Two`
- `268 Missing Number`
- `371 Sum of Two Integers`

補題：

- `338 Counting Bits`
- `461 Hamming Distance`
- `342 Power of Four`
- `393 UTF-8 Validation`

基礎筆記：

- bit mask
- set / clear / toggle / check bit
- endianness
- integer overflow
- signed / unsigned
- shift 的陷阱

### 第 2 週：指標、字串、陣列、雙指標

重刷：

- `8 String to Integer`
- `151 Reverse Words in a String`
- `167 Two Sum II`
- `209 Minimum Size Subarray Sum`
- `3 Longest Substring Without Repeating Characters`

補題：

- `125 Valid Palindrome`
- `283 Move Zeroes`
- `88 Merge Sorted Array`
- `27 Remove Element`

基礎筆記：

- `char*`
- 陣列退化成指標
- `strlen` 成本
- buffer boundary
- `memset` / `memcpy` / `memmove` 差異

### 第 3 週：鏈結串列、Stack、Queue、韌體常見資料結構

重刷：

- `141 Linked List Cycle`
- `142 Linked List Cycle II`
- `206 Reverse Linked List`
- `19 Remove Nth Node From End of List`
- `20 Valid Parentheses`
- `232 Implement Queue using Stacks`
- `146 LRU Cache`

補題：

- `21 Merge Two Sorted Lists`
- `2 Add Two Numbers`
- `155 Min Stack`
- `622 Design Circular Queue`

基礎筆記：

- 快慢指標
- dummy node
- `malloc` / `free` ownership
- double free
- memory leak
- circular buffer

### 第 4 週：面試整合與中等題穩定度

重刷：

- `33 Search in Rotated Sorted Array`
- `34 Find First and Last Position of Element in Sorted Array`
- `48 Rotate Image`
- `54 Merge Intervals`
- `200 Number of Islands`
- `207 Course Schedule`
- `739 Daily Temperatures`

補題：

- `704 Binary Search` 如果要用 C 重寫
- `215 Kth Largest Element in an Array`
- `994 Rotting Oranges`

模擬：

- 每週至少 2 題限時 35 分鐘。
- 盡量用 C 寫。
- 寫完後口頭說明：
  - 思路
  - 複雜度
  - 邊界條件
  - 如果在韌體環境，記憶體或效能要注意什麼

Linux kernel 加分任務：

- 如果本週時間夠，完成一個最小 character device driver。
- 可以做到 `insmod`、`dmesg` 看到 log、`rmmod` 正常卸載即可。
- 不要求一次學完整 driver model，先有手感最重要。

## 題目整理規則

每題檔案頂部盡量補一小段註解：

```c
/*
 * Core idea:
 * Time:
 * Space:
 * C notes:
 * Interview notes:
 */
```

可以用英文短句，避免檔案內中英文太混雜；如果是自己複習筆記，也可以用繁中。

建議每題整理時固定回答：

- 這題核心技巧是什麼？
- 為什麼這樣寫不會越界？
- 有沒有 integer overflow？
- 有沒有配置記憶體？誰負責釋放？
- 如果輸入是空、只有一個元素、極大值、重複值，會怎樣？
- 面試官如果要你改成 embedded-style，哪些地方要調整？

## Common 資料夾定位

`Common` 建議用來放韌體面試常見基礎，不只是 LeetCode 單題答案：

- circular buffer
- LRU cache
- bit operation helpers
- `memset` / `memmove` / `memcpy` 範例
- linked list 基本操作
- queue / stack 的 C 實作

未來如果要新增工具型範例，優先放在 `Common`，題目答案則維持放在 `Easy`、`Medium`、`Hard`。

## 每週驗收

- 至少完成 6 到 10 題。
- 至少 1 份「容易忘的 C 基礎」筆記。
- 至少 2 題限時 35 分鐘。
- 每週回頭重刷 2 題前一週做過的題目。
- 不只看 AC，也要確認：
  - 有沒有越界
  - 有沒有 leak
  - 有沒有 overflow
  - 有沒有不必要的 O(n^2)

## 4 週總驗收

- 完成至少 35 題高優先題。
- 至少 25 題用 C 重寫或重刷。
- 能熟講以下主題：
  - 位元操作
  - 指標與記憶體
  - linked list
  - circular buffer
  - LRU
  - binary search
  - sliding window
- 面試時能把 LeetCode 練習連回履歷中的嵌入式背景，而不是只說「我有刷題」。

## 學習紀錄

### 2026-06-06 22:08 +08:00

今天將 `linux-kernel-driver-demo` Phase 2 ioctl 整理版搬進獨立 repo `~/workspace/rpi5-kernel-driver-lab`，並補齊展示用文件與測試紀錄。

完成項目：

- 從練習專案搬移整理版檔案到乾淨 repo：
  - `include/walker_ioctl.h`
  - `driver/walker_chrdev_ioctl.c`
  - `user/walker_ioctl_test.c`
- 更新乾淨 repo：
  - `Makefile`
  - `user/Makefile`
  - `.gitignore`
  - `README.md`
  - `codex.md`
- 新增文件：
  - `docs/test_log.md`
  - `docs/user_kernel_flow.md`
- `.gitignore` 已確認會忽略：
  - `.o`
  - `.ko`
  - `.mod.c`
  - `Module.symvers`
  - `modules.order`
  - `user/walker_rw_test`
  - `user/walker_ioctl_test`
  - `*practice*` 檔案

實測結果：

- 在 `~/workspace/rpi5-kernel-driver-lab` 執行：
  - `make`
  - `make user`
  - `sudo insmod driver/walker_chrdev_ioctl.ko`
  - `sudo ./user/walker_ioctl_test /dev/walker_ioctl 'repo ioctl smoke'`
  - `sudo rmmod walker_chrdev_ioctl`
- user program 成功輸出：
  - `device          : /dev/walker_ioctl`
  - `wrote           : 16 bytes`
  - `size via ioctl  : 16 bytes`
  - `read            : 16 bytes`
  - `data            : repo ioctl smoke`
  - `mode via ioctl  : 7`
  - `reset via ioctl : ok`
- `dmesg` 已看到 `walker_ioctl: reset buffer` 與 `walker_ioctl: removed /dev/walker_ioctl`。

Git 狀態：

- 乾淨 repo 已提交：
  - `296f7de Add ioctl driver phase`
  - 前一個 commit：`986f91f Initial Raspberry Pi kernel driver lab`
- 目前沒有未提交原始檔，只有被 `.gitignore` 忽略的 build outputs。

關於 `docs/test_log.md`：

- 這份文件就是測試手冊與驗證紀錄，應包含如何 build、如何 `insmod` 掛 module、如何檢查 `/dev` 節點、如何跑 user-space test、如何看 `dmesg`、如何 `rmmod` 卸載，以及代表性輸出。

### 2026-06-06 21:52 +08:00

今天檢查使用者重寫的 `linux-kernel-driver-demo` Phase 2 ioctl practice 版本，並完成修正後的 Raspberry Pi 實機測試。

完成項目：

- 使用者新增 / 修改 ioctl practice 相關檔案：
  - `include/walker_ioctl_practice.h`
  - `driver/walker_chrdev_ioctl_practice.c`
- `Makefile` 已加入：
  - `obj-m += driver/walker_chrdev_ioctl_practice.o`
- 重新編譯成功：
  - `make`
  - `make -C user`
- 載入並測試 practice driver：
  - `sudo insmod driver/walker_chrdev_ioctl_practice.ko`
  - `sudo ./user/walker_ioctl_test /dev/walker_ioctl_practice 'fixed ioctl practice'`
  - `sudo rmmod walker_chrdev_ioctl_practice`

修正重點：

- 初版 `WALKER_IOCTL_RESET` case 少了 `return 0;`，導致 switch fall-through 到 `WALKER_IOCTL_GET_BUFFER_SIZE`。
- fall-through 造成 `RESET` 後又執行 `GET_BUFFER_SIZE`，實測時 user-space 的 `mode` 被污染成 `0`。
- 修正後 `RESET` 不再掉進 `GET_BUFFER_SIZE`，user-space 輸出中的 `mode via ioctl` 正常維持 `7`。

實測結果：

- user program 輸出：
  - `device          : /dev/walker_ioctl_practice`
  - `wrote           : 20 bytes`
  - `size via ioctl  : 20 bytes`
  - `read            : 20 bytes`
  - `data            : fixed ioctl practice`
  - `mode via ioctl  : 7`
  - `reset via ioctl : ok`
- `dmesg` 已看到：
  - `walker_ioctl: created /dev/walker_ioctl_practice`
  - `walker_ioctl: wrote 20 bytes`
  - `walker_ioctl: get buffer size=20`
  - `walker_ioctl: set mode=7`
  - `walker_ioctl: removed /dev/walker_ioctl_practice`

目前狀態：

- Phase 2 ioctl practice driver 已可編譯、載入、測試與卸載。
- 使用者同步補強了 `file` 的 `ppos` 觀念與 ioctl 基礎知識。
- 下一步可以整理 Phase 2 README / test log，或開始把整理版 ioctl 功能移植到獨立 git repo `~/workspace/rpi5-kernel-driver-lab`。

### 2026-05-29 16:20 +08:00

今天開始 `linux-kernel-driver-demo` Phase 2 ioctl 參考版，先由 Codex 寫一份可跑範例，供使用者閱讀後再自行重寫練習版。

完成項目：

- 在 Raspberry Pi 的 `~/workspace/linux-kernel-driver-demo` 新增：
  - `include/walker_ioctl.h`
  - `driver/walker_chrdev_ioctl.c`
  - `user/walker_ioctl_test.c`
- 更新 Raspberry Pi 專案的 `Makefile`：
  - 新增 `obj-m += driver/walker_chrdev_ioctl.o`
- 更新 `user/Makefile`：
  - 新增 `walker_ioctl_test`
- ioctl commands：
  - `WALKER_IOCTL_RESET`
  - `WALKER_IOCTL_GET_BUFFER_SIZE`
  - `WALKER_IOCTL_SET_MODE`
- driver 新增 `.unlocked_ioctl = walker_ioctl`，並用 `copy_to_user()` / `copy_from_user()` 傳遞 ioctl 參數。

實測結果：

- 在 Raspberry Pi 上執行 `make` 與 `make -C user` 成功。
- 載入 `driver/walker_chrdev_ioctl.ko` 後成功建立 `/dev/walker_ioctl`。
- 執行 `sudo ./user/walker_ioctl_test` 成功輸出：
  - `wrote           : 18 bytes`
  - `size via ioctl  : 18 bytes`
  - `read            : 18 bytes`
  - `data            : hello ioctl driver`
  - `mode via ioctl  : 7`
  - `reset via ioctl : ok`
- `dmesg` 已看到：
  - `walker_ioctl: created /dev/walker_ioctl`
  - `walker_ioctl: get buffer size=18`
  - `walker_ioctl: set mode=7`
  - `walker_ioctl: reset buffer`
  - `walker_ioctl: removed /dev/walker_ioctl`

目前狀態：

- Phase 2 參考版已可編譯與實機測試。
- 下一步建議使用者閱讀 `walker_ioctl.h`、`walker_chrdev_ioctl.c`、`walker_ioctl_test.c` 後，另外重寫一份 practice 版本。

### 2026-05-26 22:07 +08:00

今天在 Raspberry Pi 5 的 `linux-kernel-driver-demo` 中新增 user-space read/write demo，讓 Phase 1 character device driver 不只用 `echo` / `cat` 測，也能用一般 C 程式透過 system call 操作 `/dev/walker_practice`。

完成項目：

- 在 Pi 上新增：
  - `~/workspace/linux-kernel-driver-demo/user/walker_rw_test.c`
  - `~/workspace/linux-kernel-driver-demo/user/Makefile`
- `walker_rw_test.c` 會執行：
  - `open("/dev/walker_practice", O_RDWR)`
  - `write()` 寫入 `hello from user-space test`
  - `read()` 從同一個 device fd 讀回資料
  - `close()`
- 在 Pi 上執行 `make -C user` 成功，產生 `user/walker_rw_test`。
- 載入 `driver/walker_chrdev_practice.ko` 後，執行 `sudo ./user/walker_rw_test` 成功。

實測結果：

- user program 輸出：
  - `device: /dev/walker_practice`
  - `wrote : 26 bytes`
  - `read  : 26 bytes`
  - `data  : hello from user-space test`
- `dmesg` 已看到：
  - `walker_practice: open`
  - `walker_practice: wrote 26 bytes`
  - `walker_practice: release`
  - `walker_chrdev: removed /dev/walker_practice`

目前狀態：

- Phase 1 已從 shell 測試推進到 user-space C 測試。
- 下一步若繼續往下，適合整理 README / test log，然後進 Phase 2 ioctl。

### 2026-05-24 18:32 +08:00

今天完成一組「2 題複習 + 1 題新題」並整理成可提交版本。

完成項目：

- 修正 `Medium/209-Minimum Size Subarray Sum/C.c`：移除 `fmin()`，改用純整數比較更新最短長度。
- 修正 `Medium/3-Longest Substring Without Repeating Characters/C.c`：
  - 先檢查 `s == NULL` 再呼叫 `strlen()`。
  - 將字元表改成 256 格並用 `unsigned char` 當索引。
  - 加上 `malloc` 失敗檢查。
  - 移除 `fmax()`，改用整數比較。
- 修正 `Easy/125-Valid Palindrome/C.c`：
  - 保留 `<stdlib.h>` 讓 `NULL` 來源明確。
  - 新增 ASCII helper：`is_ascii_alnum()` 與 `to_ascii_lower()`。
  - 不再修改輸入字串，只在比較時轉成小寫。

目前狀態：

- 今日題目已整理完成，準備提交推送。
- 工作區同時有 `Medium/3-Sum/C.cpp` -> `Medium/3-Sum/C++.cpp` 的檔名整理，提交前需一起確認。

### 2026-05-24 18:30 +08:00

今天第三題完成新題 `125 Valid Palindrome`，練習 C 字元處理與雙指標。

完成項目：

- 使用者新增 `Easy/125-Valid Palindrome/C.c`。
- 檢查目前版本：使用 left/right 雙指標，跳過非英數字元，並手刻 ASCII 大小寫處理。
- 今天題目配比完成：複習 `209`、複習 `3`、新題 `125`。

目前狀態：

- `125` 主要測資方向可行。
- 建議避免直接修改輸入字串；目前版本遇到大寫字母會用 `s[left] += 32` 或 `s[right] += 32` 直接改原字串，面試寫法建議改成 helper 回傳比較用的小寫字元。
- 可把「是否英數」與「轉小寫」拆成兩個 helper，邏輯會比巢狀 while 更好講。
- 工作區仍顯示 `Medium/3-Sum/C.cpp` 被刪除且有未追蹤 `Medium/3-Sum/C++.cpp`，看起來像檔名整理；提交前需確認是否為使用者有意重新命名。

### 2026-05-24 17:47 +08:00

今天第二題複習 `3 Longest Substring Without Repeating Characters`。

完成項目：

- 使用者更新 `Medium/3-Longest Substring Without Repeating Characters/C.c`。
- 檢查目前版本：採用 sliding window 與 `record_map` 記錄字元最後出現位置，方向正確。
- 目前工作區也顯示 `Medium/3-Sum/C.cpp` 被刪除，且有未追蹤的 `Medium/3-Sum/C++.cpp`，看起來像檔名整理；提交前要確認是否為使用者有意重新命名。

目前狀態：

- `3` 的演算法方向正確，但 C 細節需修正後再視為完成：
  - `strlen(s)` 在 `s == NULL` 檢查前呼叫，若傳入 NULL 會崩潰。
  - `memset(record_map, -1, sizeof(int))` 只初始化一個 int，應初始化整個 128 個 int。
  - `malloc` 後需要檢查是否為 NULL。
  - `fmax()` 是浮點函式，整數長度比較建議改用三元運算或整數 helper。
  - 若假設 ASCII，可使用 128；更保守可用 256 並以 `unsigned char` 當索引。

### 2026-05-24 16:08 +08:00

今天回到 LeetCode 主線，先複習 `209 Minimum Size Subarray Sum`。

完成項目：

- 使用者更新 `Medium/209-Minimum Size Subarray Sum/C.c`。
- 檢查後確認 sliding window 邏輯正確：右指標擴張累加，當 sum 達標時用左指標收縮，並更新最小長度。
- 新寫法刪除了前置 `numsSize <= 0` 判斷；目前仍可正確處理 `numsSize == 0`，因為迴圈不會進入，最後回傳 0。

目前狀態：

- `209` 靜態檢查通過。
- 建議避免在整數比較中使用 `fmin()`，因為它是浮點函式、回傳 `double`，純 C 面試寫法可改成三元運算或整數 helper。
- 下一題仍建議照配比進行：複習 `3 Longest Substring Without Repeating Characters`，再做新題 `125 Valid Palindrome`。

### 2026-05-22 21:33 +08:00

今天確認 Codex 已可直接透過 `ssh rpi` 連到 Raspberry Pi 5，並在 Pi 上完成 `linux-kernel-driver-demo` Phase 1 character device driver 的實機 smoke test。

完成項目：

- 透過 SSH 確認 Raspberry Pi 端狀態：
  - user：`subserver5`
  - host：`SubServer5`
  - OS：`Debian GNU/Linux 12 (bookworm)`
  - architecture：`arm64`
  - kernel：`6.12.87+rpt-rpi-2712`
  - board：`Raspberry Pi 5 Model B Rev 1.0`
  - headers：`/lib/modules/6.12.87+rpt-rpi-2712/build -> /usr/src/linux-headers-6.12.87+rpt-rpi-2712`
- 檢查 Pi 上專案檔案：
  - `~/workspace/linux-kernel-driver-demo/Makefile`
  - `~/workspace/linux-kernel-driver-demo/driver/hello_module.c`
  - `~/workspace/linux-kernel-driver-demo/driver/walker_chrdev.c`
- 在 Pi 上執行 `make` 成功，產生：
  - `driver/hello_module.ko`
  - `driver/walker_chrdev.ko`
- 實機載入並測試 `walker_chrdev` 成功：
  - `sudo insmod driver/walker_chrdev.ko`
  - `/dev/walker_demo` 成功建立，權限顯示為 `crw------- root root`
  - 使用 `echo "hello from codex ssh" | sudo tee /dev/walker_demo` 寫入成功
  - 使用 `sudo cat /dev/walker_demo` 讀回 `hello from codex ssh`
  - `sudo rmmod walker_chrdev` 卸載成功

目前狀態：

- Phase 0 hello kernel module 已完成並通過實機測試。
- Phase 1 character device driver 已完成基本 `open` / `release` / `read` / `write` smoke test。
- `dmesg` 已看到 `walker_chrdev: created /dev/walker_demo`、`wrote 21 bytes`、`removed /dev/walker_demo`。
- 依照支線規則，Phase 0 / Phase 1 已有 Raspberry Pi 實機測試結果；下一步可以先補 README 與 API 解釋，或在確認學習節奏後再進 Phase 2 ioctl。

注意事項：

- `/dev/walker_demo` 目前由 `device_create()` 建立後預設是 `root:root`、`crw-------`，所以一般使用者需要 `sudo` 才能讀寫。
- 目前 smoke test 只驗證單一 buffer 的基本讀寫；還沒處理多 reader/writer、權限規則、udev rule、partial write policy 或 ioctl。

### 2026-05-17 16:16 +08:00

面試前最後整理：確認今日 MCU 面試複習檔案與 repo 狀態，準備推送到 GitHub。

完成項目：

- 盤點目前 repo 檔案統計：
  - `.c`: 58
  - `.cpp`: 15
  - `.py`: 2
  - `.md`: 1
  - `.json`: 1
- 盤點資料夾檔案數：
  - `.vscode`: 1
  - `Common`: 6
  - `Easy`: 29
  - `Medium`: 39
  - `Hard`: 1
- 確認本次變更包含：
  - 新增 `Common/CAN_encoder.c`
  - 更新 `Easy/206-Reverse Linked List/C.c`
  - 更新 `Easy/141-Linked List Cycle/C.c`
  - 新增 `Easy/21-Merge Two Sorted Lists/C.c`
  - 刪除 `Common/print_pyramid.c`
  - 刪除舊路徑 `Easy/20-Merge Two Sorted Lists/C++.cpp`
- 使用者確認刪除是有意整理，`Merge Two Sorted Lists` 改放到正確的 LeetCode 21 路徑。

目前狀態：

- 今天主軸是 MCU 面試前複習，重點為 CAN encode/decode 與 linked list 三題。
- 尚未本機編譯驗證，主要完成靜態檢查與面試說明整理。
- 提交前仍需注意 CAN decode 的 cast 位置可再寫得更乾淨，但目前不直接改使用者程式。

### 2026-05-17 16:06 +08:00

明天 MCU 面試前，完成 CAN encode/decode 與 linked list 三題複習。

完成項目：

- 使用者完成 `Common/CAN_encoder.c`，練習 8-byte CAN payload 的 little-endian encode/decode。
- 使用者完成 linked list 三題：
  - `Easy/206-Reverse Linked List/C.c`
  - `Easy/141-Linked List Cycle/C.c`
  - `Easy/21-Merge Two Sorted Lists/C.c`
- 檢查 `206 Reverse Linked List`：使用 iterative 三指標思路，先保存 next，再反轉 `next` 指標，最後回傳新 head。
- 檢查 `141 Linked List Cycle`：使用 Floyd slow/fast pointer，透過節點位址相遇判斷是否有環。
- 檢查 `21 Merge Two Sorted Lists`：使用 dummy head 串接原節點，不額外複製 list 節點。

目前狀態：

- 四個檔案皆已完成靜態檢查。
- CAN decode 建議把 cast 寫成 `((uint16_t)data[1] << 8)` 與 `((uint16_t)data[3] << 8)`，語意更清楚。
- CAN signed angle decode 可用 `(int16_t)raw_angle` 表示把 raw 16-bit pattern 解回 signed value。
- `Merge Two Sorted Lists` 目前用 `malloc` 配 dummy head 並在回傳前 `free`，邏輯可行；面試時更推薦 stack dummy，避免不必要配置與 `malloc` 失敗處理。
- `git status` 顯示 `Common/print_pyramid.c` 與 `Easy/20-Merge Two Sorted Lists/C++.cpp` 被刪除，提交前要確認是否為使用者有意整理路徑。

### 2026-05-17 15:14 +08:00

明天 MCU 面試前，今天改練 CAN encode / decode 與 linked list 面試題。

完成項目：

- 使用者新增 `Common/CAN_encoder.c`，內容包含 `encode_can_payload()` 與 `decode_can_payload()`。
- 檢查目前 CAN 版本：固定 8-byte payload，`rpm` 使用 `uint16_t`，`angle` 使用 `int16_t`，`status` 使用 `uint8_t`，byte 5 到 byte 7 清為 0。
- 討論 CAN payload 的 endianness：這裡指的是多 byte signal 的 byte order，不是 byte 內部 bit order。
- 討論函式參數：`uint8_t data[8]` 在 C 函式參數中會退化成 `uint8_t *data`，`[8]` 主要是表達預期至少有 8 bytes，不會真的由編譯器保證長度。

目前狀態：

- CAN encode/decode 靜態檢查大方向正確。
- 建議修正 signed `angle` 的 encode：先轉成 `uint16_t raw_angle = (uint16_t)angle;` 再 shift，避免 signed negative right shift 的 implementation-defined 行為。
- 建議修正 decode cast：使用 `((uint16_t)data[1] << 8)`，把 byte 先轉寬再左移，語意更乾淨。
- `git status` 顯示 `Common/print_pyramid.c` 被刪除；尚未確認是否為使用者有意刪除，後續提交前要確認。

### 2026-05-16 15:53 +08:00

今天完成一組位元操作題：`371 Sum of Two Integers`、`190 Reverse Bits`、`338 Counting Bits`。

完成項目：

- 檢查 `Medium/371-Sum of Two Integers/C.c`：目前採逐 bit full-adder 寫法，邏輯方向正確。
- 檢查 `Easy/190-Reverse Bits/C.c`：包含 32-bit 逐位反轉版本與 bit-swap 優化版本。
- 檢查 `Easy/338-Counting Bits/C.c`：使用 `result[i & (i - 1)] + 1`，透過清除最低位的 `1` 來沿用已計算結果。

目前狀態：

- 三題都已完成靜態檢查。
- 尚未編譯驗證。
- `190` 的 `better_soulation()` 可再注意參數型別：若使用 bit-swap mask 做右移，建議實作時用 `uint32_t` 或 `unsigned int` 暫存，避免 signed right shift 的語意差異。
- `338` 可再補 `calloc` 失敗檢查，並在失敗時設定 `*returnSize = 0`。
- 使用者提醒：下次安排題目時要分配複習舊題與刷新題目的比例，不要只一路推新題。

### 2026-05-16 15:36 +08:00

今天回到位元操作主線，開始練習 `371 Sum of Two Integers`。

完成項目：

- 使用者更新 `Medium/371-Sum of Two Integers/C.c`。
- 檢查目前版本：採用逐 bit full-adder 的想法，用 `a_bit ^ b_bit ^ carry` 產生結果 bit，並用三個 bit 中至少兩個為 1 來產生下一位 carry。
- 討論 C 型別細節：`1U << i` 讓遮罩是 unsigned；`a & (1U << i)` 會把 `a` 轉成 unsigned 後運算；若參與 shift 的值是 unsigned，可避免 `1 << 31` 這類 signed shift 未定義行為。

目前狀態：

- `371` 目前靜態檢查邏輯方向正確。
- 尚未編譯驗證。
- 可再考慮把 `temp` 命名為 `carry`，讓面試說明更直覺。

### 2026-05-15 18:19 +08:00

今天接上 `linux-kernel-driver-demo` 支線，先把 Raspberry Pi 5 本機 kernel module 開發環境整理起來，並完成 Phase 0 hello kernel module 實機測試。

完成項目：

- Raspberry Pi 5 可從 Windows 端 ping 到，SSH 服務可連線；登入失敗主因是帳號大小寫錯誤，Windows SSH config 已從 `SubServer5` 修成 `subserver5`。
- Raspberry Pi 端確認環境：
  - kernel：`6.12.87+rpt-rpi-2712`
  - board：`Raspberry Pi 5 Model B Rev 1.0`
  - headers：`/lib/modules/6.12.87+rpt-rpi-2712/build -> /usr/src/linux-headers-6.12.87+rpt-rpi-2712`
- 安裝 Raspberry Pi 本機開發工具時，`ltrace` 在目前套件來源中找不到，已改用不含 `ltrace` 的安裝清單；這不影響 kernel module 開發。
- 建立並編譯 `~/workspace/linux-kernel-driver-demo` 的 Phase 0：
  - `driver/hello_module.c`
  - repo-root `Makefile`
- 使用 Raspberry Pi 實機測試通過：
  - `make`
  - `sudo insmod driver/hello_module.ko`
  - `lsmod | grep hello`
  - `dmesg | tail -20`
  - `sudo rmmod hello_module`
  - `dmesg | tail -20`

目前狀態：

- `hello_module` 可成功載入與卸載。
- `dmesg` 已看到：
  - `hello_module: loaded on Raspberry Pi 5`
  - `hello_module: unloaded`
- Phase 0 完成；下一步進 Phase 1 character device driver，目標是建立 `/dev/walker_demo`，支援基本 `open` / `release` / `read` / `write`。

注意事項：

- Linux 帳號大小寫敏感，`SubServer5` 和 `subserver5` 是不同帳號。
- `pr_info()` 可視為較現代且帶 log level 的 `printk(KERN_INFO ...)` 寫法。
- `__init` / `__exit` 是 kernel section 標記；只在載入或卸載階段使用的函式適合加，會被正常執行階段呼叫的函式不要加。

### 2026-05-13 16:57 +08:00

今天開始 `338 Counting Bits`，延續 `231 Power of Two` 的 `n & (n - 1)` 位元技巧。

完成項目：

- 使用者新增 `Easy/338-Counting Bits/C.c`。
- 初版使用 Brian Kernighan loop：對每個 `i` 重複用 `temp &= temp - 1` 清掉最低位的 1，逐步累加 bit count。
- 檢查後判斷此版本邏輯可算出正確答案，但更像把 `191 Number of 1 Bits` 套到每個數字上，還不是 `338` 最推薦的 O(n) DP 解法。

目前狀態：

- 使用者已將核心迴圈改成 `result[i] = result[i & (i - 1)] + 1;`，讓每個 `i` 用前面已算好的答案 O(1) 推出。
- 教學理解點：`i & (i - 1)` 會把 `i` 最右邊的 1 拔掉，得到一個比較小的 index；該 index 對應的 bit count 已經算好，所以再 `+1` 就是 `i` 的 1 數量。
- `338 Counting Bits` 的 DP 解法靜態檢查看起來正確；尚未用本機編譯器驗證。
- 下一步若繼續位元操作，可接 `461 Hamming Distance` 或 `342 Power of Four`；若想整理，可補 `231` / `268` / `338` 的題頭筆記。

### 2026-05-13 16:43 +08:00

今天完成 `231 Power of Two` 的 C 版本，練習用 `n & (n - 1)` 判斷一個數是否只有一個 bit 是 1。

完成項目：

- 使用者新增 `Easy/231-Power of Two/C.c`。
- 初版核心想法正確，但括號不足時會讓 `0` 被誤判成 true；修正後使用 `n > 0 && (n & (n - 1)) == 0`。
- 討論重點：`n > 0` 用來排除 0 和負數；`n & (n - 1)` 會清掉最低位的 1，若結果為 0，代表原本只有一個 1。

目前狀態：

- `231 Power of Two` 的 C 解法靜態檢查看起來正確。
- 下一步若繼續位元操作，建議接 `338 Counting Bits`，把 `n & (n - 1)` 延伸成 DP/bit pattern。

### 2026-05-13 16:27 +08:00

今天完成 `268 Missing Number`，延續位元操作主線練習 XOR 抵消法。

完成項目：

- 使用者重寫 `Easy/268-Missing Number/C.c`。
- 檢查後確認核心解法正確：先令 `result = numsSize`，再逐一 XOR index `i` 與 `nums[i]`，讓成對出現的數字抵消，最後留下缺少的數字。
- 釐清觀念：陣列長度是 `numsSize`，但完整數字範圍是 `0..numsSize`，所以最大值 `numsSize` 不會出現在 index 迴圈中，必須先放進初始 result。

目前狀態：

- `268 Missing Number` 的 XOR 解法靜態檢查看起來正確。
- 檔案目前尚未補題頭筆記，也尚未用本機編譯器驗證。
- 下一題建議可接 `231 Power of Two` 或 `338 Counting Bits`，繼續位元操作；若想複習 C 基礎，可補 `268` 的題頭與數學和解法比較。

### 2026-05-13 11:38 +08:00

今天接著挑戰 `137 Single Number II`，練習出現三次元素下的位元統計法。

完成項目：

- 使用者重寫 `Medium/137-Single Number II/C.c` 的 `better_memory()`。
- 檢查後確認核心解法正確：逐一統計 32 個 bit，對每個 bit 的出現次數取 mod 3，剩下的 bit 組回唯一值。
- 討論重點：使用 `1U << i` 避免 signed shift 到最高位；`result` 用 unsigned 暫存後再轉回 `int`，可處理負數結果。

目前狀態：

- `better_memory()` 靜態檢查看起來正確。
- 若要提交 LeetCode，需注意平台會呼叫 `singleNumber()`，穩定版邏輯應放在 `singleNumber()` 中。
- 舊版 `singleNumber()` 使用 `calloc` 配置 32 個 counter，但目前沒有 `free`，若保留該版本要補釋放或改用固定陣列。

### 2026-05-13 11:26 +08:00

今天延續位元操作暖身，完成 `191 Number of 1 Bits`。

完成項目：

- 使用者新增 `Easy/191-Number of 1 Bits/C.c`。
- 檢查修正版後確認使用 `n &= (n - 1)` 的 Brian Kernighan 解法正確。
- 釐清觀念：`n - 1` 會把最低位的 `1` 變成 `0`，並把右側低位 `0` 變成 `1`；真正用來清掉最低位 `1` 的操作是 `n & (n - 1)`，不是 XOR。

目前狀態：

- `191 Number of 1 Bits` 已完成靜態檢查。
- 尚未用本機編譯器驗證，因為目前開發環境剛重灌、編譯器尚未準備好。
- 下一題建議接 `268 Missing Number`，可延續 XOR 與數學和兩種解法比較。

### 2026-05-12 22:25 +08:00

今晚先在 WSL 環境準備期間回到 LeetCode 主線，暖身位元操作題。

完成項目：

- 使用者完成 `Easy/136-Single Number/C.C`。
- 檢查後確認核心 XOR 邏輯正確。
- 將解法整理成更典型的 `result = 0` 累積 XOR 寫法。
- 補上題頭筆記：核心想法、時間複雜度、空間複雜度、C 注意事項與面試說明。

目前狀態：

- `136 Single Number` 已整理完成。
- Linux 支線今天仍維持只在聊天室渲染內容，不直接建立檔案；等 WSL 開發環境準備好再搬過去。
- 下一題建議接 `191 Number of 1 Bits` 或 `268 Missing Number`，延續位元操作手感。

### 2026-05-12 00:00 +08:00

新增額外支線 `linux-kernel-driver-demo` 的專案規格。

完成項目：

- 將 Raspberry Pi Linux kernel / BSP demo 規劃整理進 `codex.md`。
- 明確把這條支線定位成履歷與面試用作品集，不和 LeetCode 主線混在一起。
- 記錄 Phase 0 到 Phase 5 的範圍與順序。
- 明確規定先做 Phase 0 和 Phase 1，完成後等待 Raspberry Pi 實機測試結果，再繼續 Phase 2。
- 加上支線進度紀錄規則：每次開始或結束支線工作，都要更新「學習紀錄」。

目前狀態：

- 尚未建立 `linux-kernel-driver-demo/` 目錄。
- 下一步若使用者要求開始，就先產生 Phase 0 與 Phase 1：
  - `driver/hello_module.c`
  - `driver/walker_chrdev.c`
  - `Makefile`
  - `README.md`

### 2026-05-08 21:13 +08:00

今晚主軸是把 `Common/Circular_Buffer.c` 從草稿整理成可面試討論的 ring buffer 範例。

完成項目：

- 補完 `rb_write()` 和 `rb_read()` 的基本邏輯。
- `rb_create()` 加上 `capacity <= 0` 防呆。
- `rb_write()` / `rb_read()` / `rb_free()` 加上 `rb == NULL` 防呆。
- `rb_read()` 改成拒絕 `len <= 0`。
- `rb_write()` 改成先算 `available = capacity - data_counter`，避免用 `data_counter + len` 造成理論上的整數溢位。
- 檔案頂部補上 ring buffer 的核心概念、複雜度與 C 注意事項。
- 使用 MSVC 檢查通過：
  - `cl /nologo /TC /W4 /Zs "Common\Circular_Buffer.c"`

今晚複習的 C / 韌體觀念：

- `volatile`：避免編譯器把可能被硬體、ISR 或其他流程改動的值錯誤快取；但 `volatile` 不等於 thread-safe。
- ISR：ISR 裡通常不拿 mutex，也不做會阻塞的事；常見做法是清 interrupt flag、讀少量資料，然後用 semaphore 或 queue 通知 task。
- Macro 副作用：
  - `#define MIN(a, b) ((a) < (b) ? (a) : (b))`
  - `MIN(*p++, b)` 會讓 `*p++` 在條件式執行一次，若條件成立，回傳分支又再執行一次。
  - 重點：運算優先序不等於求值次序；有副作用的 expression 不應傳進 macro。

下一步建議：

- 若要延續今晚內容，下一題適合補 `622 Design Circular Queue` 的 C 版本。
- 如果只想複習觀念，下一個主題可以看 `static`、`const`、函式指標或 `memcpy` / `memmove` 差異。

## 參考來源

- LeetCode Top Interview 150: https://leetcode.com/studyplan/top-interview-150/
- NeetCode 150: https://neetcode.io/practice/practice/neetcode150
- EmbeddedInterviewLab Bit Manipulation: https://embeddedinterviewlab.com/interview/coding/bits/
- LeetCode Embedded C 討論: https://leetcode.com/discuss/post/2499644/Embedded-C-FAANG-Interview-Question-with-Resources/
- Tesla Embedded Firmware 面試經驗: https://www.jointaro.com/interviews/companies/tesla/experiences/embedded-firmware-intern-palo-alto-ca-september-1-2024-no-offer-positive-0a1e6795
- 韌體工程師的 0x10 個問題: https://hackmd.io/@Chienyu/S1loEqCuo
- Linux kernel Driver Model: https://www.kernel.org/doc/html/next/driver-api/driver-model/index.html
- Linux kernel patch submission guide: https://www.kernel.org/doc/html/next/process/submitting-patches.html

## 給未來的 Codex

- 使用繁體中文回覆，語氣稍微口語一點。
- 不要一開始就大改既有解答；先確認使用者當下要的是補題、重構、註解整理，還是面試規劃。
- 如果要整理舊題，優先從位元操作、指標/記憶體、linked list、circular buffer、LRU 開始。
- 出題時要混合「複習舊題」和「刷新題目」；預設可用 2 題複習、1 題新題，或依使用者當天狀態調整。
- 如果使用者提到 `linux-kernel-driver-demo`、kernel driver、BSP、Raspberry Pi driver，就視為額外支線；每次工作都要同步更新「學習紀錄」。
- 支線目前原則是先做 Phase 0 和 Phase 1，完成後等使用者在 Raspberry Pi 上測試，再繼續 Phase 2，不要一次推進到 ioctl / Device Tree / GPIO interrupt。
- 2026-05-07 接手觀察：
  - `Common/Circular_Buffer.c` 已在 2026-05-08 整理過，包含 capacity 檢查、NULL handling、read/write wrap-around 與 MSVC `/W4 /Zs` 檢查。
  - `Common/LRU_Cache.c` 目前像草稿，`range = 10001;` 少型別，若要整理 LRU，建議先改成可編譯版本再補面試註解。
  - 多數題目檔案尚未補上 `Core idea / Time / Space / C notes / Interview notes` 題頭，可以從韌體高相關題開始逐步補。
- 下一個建議任務：
  - 接著補 LeetCode `622 Design Circular Queue` 的 C 版本，因為它和韌體 ring buffer 最直接相關，也能接到 `641 Design Circular Deque`。
  - 或整理 `Common/LRU_Cache.c`，把草稿修到可編譯，再補面試註解。
