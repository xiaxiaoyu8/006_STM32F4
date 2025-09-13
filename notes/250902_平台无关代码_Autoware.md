#ifndef _TTS_DEFINE_H_
#define _TTS_DEFINE_H_

/*-------------------------------------------------------------------------------
 编译器相关宏定义
-------------------------------------------------------------------------------*/
#define _NOP_ __nop();

/*-------------------------------------------------------------------------------
 布尔类型定义
-------------------------------------------------------------------------------*/
typedef enum
{
    FALSE1 = 0,
    TRUE1
} BOOL;

/*-------------------------------------------------------------------------------
 平台无关基本数据类型定义
-------------------------------------------------------------------------------*/

/* 有符号整数类型 */
typedef signed char         int8;
typedef signed char         i8;
typedef signed short int    int16;
typedef signed short int    i16;
typedef signed int          int32;
typedef signed int          i32;
typedef signed long int     int64;
typedef signed long int     i64;

/* 无符号整数类型 */
typedef unsigned char       u8;
typedef unsigned char       uint8;
typedef unsigned char       uint_8;
typedef unsigned char       uint8_t;
typedef unsigned short int  u16;
typedef unsigned short int  uint16;
typedef unsigned short int  uint_16;
typedef unsigned short int  uint16_t;
typedef unsigned short int  u16;
typedef unsigned int        u32;
typedef unsigned int        uint32;
typedef unsigned long int   uint64;
typedef unsigned long int   u64;

/* 浮点数类型 */
typedef float               f32;    /* 32位单精度浮点数 */
typedef double              f64;    /* 64位双精度浮点数 */

/* 函数指针类型 */
typedef void (*Func)(void);         /* 无参数无返回值函数指针 */
typedef void (*Func1)(u8 Val);      /* 单字节参数无返回值函数指针 */

/*-------------------------------------------------------------------------------
 实时时钟数据结构
-------------------------------------------------------------------------------*/
typedef struct
{
    u8 Year;    // 年
    u8 Month;   // 月
    u8 Day;     // 日
    u8 Hour;    // 小时
    u8 Minute;  // 分钟
    u8 Second;  // 秒钟
    u8 Week;    // 星期
    u8 Resv;    // 保留字段/天序号
} Rtos_DateTime;

/*-------------------------------------------------------------------------------
 位掩码常量定义 - 用于位操作和状态标志
-------------------------------------------------------------------------------*/
#define S_0     0x00000001U     /* 位0掩码 */
#define S_1     0x00000002U     /* 位1掩码 */
#define S_2     0x00000004U     /* 位2掩码 */
#define S_3     0x00000008U     /* 位3掩码 */
#define S_4     0x00000010U     /* 位4掩码 */
#define S_5     0x00000020U     /* 位5掩码 */
#define S_6     0x00000040U     /* 位6掩码 */
#define S_7     0x00000080U     /* 位7掩码 */
#define S_8     0x00000100U     /* 位8掩码 */
#define S_9     0x00000200U     /* 位9掩码 */
#define S_10    0x00000400U     /* 位10掩码 */
#define S_11    0x00000800U     /* 位11掩码 */
#define S_12    0x00001000U     /* 位12掩码 */
#define S_13    0x00002000U     /* 位13掩码 */
#define S_14    0x00004000U     /* 位14掩码 */
#define S_15    0x00008000U     /* 位15掩码 */
#define S_16    0x00010000U     /* 位16掩码 */
#define S_17    0x00020000U     /* 位17掩码 */
#define S_18    0x00040000U     /* 位18掩码 */
#define S_19    0x00080000U     /* 位19掩码 */
#define S_20    0x00100000U     /* 位20掩码 */
#define S_21    0x00200000U     /* 位21掩码 */
#define S_22    0x00400000U     /* 位22掩码 */
#define S_23    0x00800000U     /* 位23掩码 */
#define S_24    0x01000000U     /* 位24掩码 */
#define S_25    0x02000000U     /* 位25掩码 */
#define S_26    0x04000000U     /* 位26掩码 */
#define S_27    0x08000000U     /* 位27掩码 */
#define S_28    0x10000000U     /* 位28掩码 */
#define S_29    0x20000000U     /* 位29掩码 */
#define S_30    0x40000000U     /* 位30掩码 */
#define S_31    0x80000000U     /* 位31掩码 */

#endif /* _TTS_DEFINE_H_ */