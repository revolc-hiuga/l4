def main():
    while True:
        command = input("请输入命令：")
        if command == "ver":
            print_version()
        elif command == "help":
            print_help()
        elif command == "quit":
            break
        else:
            print("您输入的表达式为：", command, "\n")

def print_version():
    print("狮心L4计算器 作者：日向 2026")
    print("版本：0.0 build: 3")
    print()

def print_help():
    print("可用命令：")
    print("ver\t\t显示当前版本")
    print("help\t\t显示帮助信息")
    print("quit\t\t退出程序")
    print("如果输入的内容不是上述命令之一，将会将其视为表达式计算。")
    print()

if __name__ == "__main__":
    main()
