#1/bin/python3

for i in range(8):
    fprint = "yDBGMultiPrint"
    fname = f"{fprint}{i}"
    fname_prev = f"{fprint}{i-1}"
    args = ['a'+str(k) for k in range(1,i+1)]
    final_str = '] MYDBG\\n'
    eol = "\\n"
    print(f"""#define {fname}({', '.join(args)}) std::cerr << "MYDEBUG[ " << {' << '.join([ '#'+a+' " = " << ' + a + ' << "' + eol + '"' for a in args ] )} "{final_str}" """)
