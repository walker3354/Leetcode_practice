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
  - `.c`: 54
  - `.cpp`: 15
  - `.py`: 2
  - `.json`: 1
- 各資料夾目前檔案數：
  - `.vscode`: 1
  - `Common`: 6
  - `Easy`: 25
  - `Medium`: 39
  - `Hard`: 1
- 目前 git 狀態：
  - branch: `master...origin/master`
  - 2026-05-07 檢查時工作區乾淨，`master` 與 `origin/master` 同步。
  - 最新提交：`b8ccc79 add codex to trace`。
  - 本機 `rg` 目前執行會被權限擋住，掃 repo 可先用 PowerShell `Get-ChildItem`。

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
- 如果使用者提到 `linux-kernel-driver-demo`、kernel driver、BSP、Raspberry Pi driver，就視為額外支線；每次工作都要同步更新「學習紀錄」。
- 支線目前原則是先做 Phase 0 和 Phase 1，完成後等使用者在 Raspberry Pi 上測試，再繼續 Phase 2，不要一次推進到 ioctl / Device Tree / GPIO interrupt。
- 2026-05-07 接手觀察：
  - `Common/Circular_Buffer.c` 已在 2026-05-08 整理過，包含 capacity 檢查、NULL handling、read/write wrap-around 與 MSVC `/W4 /Zs` 檢查。
  - `Common/LRU_Cache.c` 目前像草稿，`range = 10001;` 少型別，若要整理 LRU，建議先改成可編譯版本再補面試註解。
  - 多數題目檔案尚未補上 `Core idea / Time / Space / C notes / Interview notes` 題頭，可以從韌體高相關題開始逐步補。
- 下一個建議任務：
  - 接著補 LeetCode `622 Design Circular Queue` 的 C 版本，因為它和韌體 ring buffer 最直接相關，也能接到 `641 Design Circular Deque`。
  - 或整理 `Common/LRU_Cache.c`，把草稿修到可編譯，再補面試註解。
