def main():
    while True:
        command = input("> ")
        command = command.strip()
        
        if command == "ver":
            print_version()
        elif command == "help":
            print_help()
        elif command == "quit":
            break
        elif command == "":
            continue
        else:
            array = split_str(command)
            print("分割后的字符串：", array)

def print_version():
    print("狮心L4计算器 作者：日向 2026")
    print("版本：0.0 build: 6")
    print()

def print_help():
    print("可用命令：")
    print("ver\t\t显示当前版本")
    print("help\t\t显示帮助信息")
    print("quit\t\t退出程序")
    print("如果输入的内容不是上述命令之一，将会将其视为表达式计算。")
    print()

# 判断字符串是否为一个数字。
# 如果是，返回True. 否则，返回False.
def is_number(s:str) -> bool:
    if s.__sizeof__ == 0:
        return False

    # 如果字符串本身全部由数字构成，就直接返回True.
    if s.isdigit():
        return True

    # 我们只允许一种情况的非数字字符：那就是数字中间的小数点。
    # 以 . 为分隔符分割字符串，如果能够分割成两份，并且两份都由数字构成，就返回True.
    array = s.split('.')
    if len(array) != 2:
        return False
    return array[0].isdigit() and array[1].isdigit()

SPLIT_STR_STATE_START = 1
SPLIT_STR_STATE_NUM = 2
SPLIT_STR_STATE_OTHER = 3

# 分割字符串
# 将字符串按照一定规则分割为字符串列表
def split_str(s:str) -> list[str]:
    state = SPLIT_STR_STATE_START
    num_str = ""
    result:list[str] = []

    for c in s:
        if state == SPLIT_STR_STATE_START:
            if c.isdigit() or c == '.':
                num_str += c
                state = SPLIT_STR_STATE_NUM
            else:
                if c != " ":
                    result.append(c)
                state = SPLIT_STR_STATE_OTHER
        elif state == SPLIT_STR_STATE_NUM:
            if c.isdigit() or c == '.':
                num_str += c
            else:
                result.append(num_str)
                num_str = ""

                if c != " ":
                    result.append(c)
                state = SPLIT_STR_STATE_OTHER
        else:   # SPLIT_STR_STARE_OTHER
            if c.isdigit() or c == '.':
                num_str += c
                state = SPLIT_STR_STATE_NUM
            else:
                if c != " ":
                    result.append(c)

    if num_str != "":
        result.append(num_str)
    return result

if __name__ == "__main__":
    main()
