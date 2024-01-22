
//Example of variadic parameter (up to 8) debug print macro

//taken form stackoverflow anseer - old trick with __VA_NARGS__

// get number of arguments with __NARG__
#define __NARG__(...)  __NARG_I_(__VA_ARGS__,__RSEQ_N())
#define __NARG_I_(...) __ARG_N(__VA_ARGS__)
#define __ARG_N( \for i in range(1,4):
      _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \    fprint = "yDBGMultiPrint"
     _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \    fname = f"{fprint}{i}"
     _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \    fname_prev = f"{fprint}{i-1}"
     _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \    args = ['a'+str(k) for k in range(1,i+1)]
     _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \    print(f"""#define {fname}({', '.join(args)}) {fname_prev}({', '.join(args
     _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
     _61,_62,_63,N,...) N#define yDBGMultiPrint1(a1) yDBGMultiPrint0() << #a1 " = " << a1 << '\n'
#define __RSEQ_N() \#define yDBGMultiPrint2(a1, a2) yDBGMultiPrint1(a1) << #a2 " = " << a2 << '\n'
     63,62,61,60,                   \#define yDBGMultiPrint3(a1, a2, a3) yDBGMultiPrint2(a1, a2) << #a3 " = " << a3 << '\n'
     59,58,57,56,55,54,53,52,51,50, \
     49,48,47,46,45,44,43,42,41,40, \
     39,38,37,36,35,34,33,32,31,30, \
     29,28,27,26,25,24,23,22,21,20, \
     19,18,17,16,15,14,13,12,11,10, \
     9,8,7,6,5,4,3,2,1,0

// general definition for any function name
#define _VFUNC_(name, n) name##n
#define _VFUNC(name, n) _VFUNC_(name, n)
#define VFUNC(func, ...) _VFUNC(func, __NARG__(__VA_ARGS__)) (__VA_ARGS__)

// definition for FOO
#define yDBGVars(...) VFUNC(yDBGMultiPrint, __VA_ARGS__)

#define yDBGMultiPrint0() std::cerr << "MYDEBUG[ " <<  "] MYDBG\n"
#define yDBGMultiPrint1(a1) std::cerr << "MYDEBUG[ " << #a1 " = " << a1 << "\n" "] MYDBG\n"
#define yDBGMultiPrint2(a1, a2) std::cerr << "MYDEBUG[ " << #a1 " = " << a1 << "\n" << #a2 " = " << a2 << "\n" "] MYDBG\n"
#define yDBGMultiPrint3(a1, a2, a3) std::cerr << "MYDEBUG[ " << #a1 " = " << a1 << "\n" << #a2 " = " << a2 << "\n" << #a3 " = " << a3 << "\n" "] MYDBG\n"
#define yDBGMultiPrint4(a1, a2, a3, a4) std::cerr << "MYDEBUG[ " << #a1 " = " << a1 << "\n" << #a2 " = " << a2 << "\n" << #a3 " = " << a3 << "\n" << #a4 " = " << a4 << "\n" "] MYDBG\n"
#define yDBGMultiPrint5(a1, a2, a3, a4, a5) std::cerr << "MYDEBUG[ " << #a1 " = " << a1 << "\n" << #a2 " = " << a2 << "\n" << #a3 " = " << a3 << "\n" << #a4 " = " << a4 << "\n" << #a5 " = " << a5 << "\n" "] MYDBG\n"
#define yDBGMultiPrint6(a1, a2, a3, a4, a5, a6) std::cerr << "MYDEBUG[ " << #a1 " = " << a1 << "\n" << #a2 " = " << a2 << "\n" << #a3 " = " << a3 << "\n" << #a4 " = " << a4 << "\n" << #a5 " = " << a5 << "\n" << #a6 " = " << a6 << "\n" "] MYDBG\n"
#define yDBGMultiPrint7(a1, a2, a3, a4, a5, a6, a7) std::cerr << "MYDEBUG[ " << #a1 " = " << a1 << "\n" << #a2 " = " << a2 << "\n" << #a3 " = " << a3 << "\n" << #a4 " = " << a4 << "\n" << #a5 " = " << a5 << "\n" << #a6 " = " << a6 << "\n" << #a7 " = " << a7 << "\n" "] MYDBG\n"
