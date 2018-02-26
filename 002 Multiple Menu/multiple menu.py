# -*- coding:utf-8 -*-
# Author: Rookie118
# Purpose: 实现三级菜单
#          Implementing three-level menu

second_menu1 = {"third_menu1":["1","2","3"],
                "third_menu2":["one","two","three"],
                "third_menu3":["一","二","三"],
                }
second_menu2 = {"third_menu4":["4","5","6"],
                "third_menu5":["four","five","six"],
                "third_menu6":["四","五","六"],
                }
second_menu3 = {"third_menu7":["7","8","9"],
                "third_menu8":["seven","eight","nine"],
                "third_menu9":["七","八","九"],
                }
first_menu = [second_menu1, second_menu2, second_menu3]

print("second_menu1:",first_menu[0])
print("second_menu2:",first_menu[1])
print("second_menu3:",first_menu[2])

flag_first_return = 'Y'   #返回第一级菜单标志
flag_second_return = 'Y'  #返回第二级菜单标志
while flag_first_return == 'Y':
    print("You have chosen the first menu.")
    flag_quit = input("Quit?(Y or N):")   #退出菜单标志
    if flag_quit == 'Y':
        break #退出程序
    else:
        second_menu_num = int(input("second menu number:"))
        if second_menu_num == 1:
            while flag_second_return == 'Y':
                print("You have chosen the second menu1.")
                flag_first_return = input("Return the upper menu?(Y or N):")
                if flag_first_return == 'N':
                    third_menu_num = int(input("third menu number:"))
                    if third_menu_num == 1:
                        print("You have chosen the third menu1:")
                        flag_second_return = input("Return the upper menu?(Y or N):")
                        if flag_second_return == 'N':
                            for menu in second_menu1["third_menu1"]:
                                print(menu)
                            flag_second_return = 'Y' #重置第二级返回标志，使程序继续运行
                    elif third_menu_num == 2:
                        print("You have chosen the third menu2:")
                        flag_second_return = input("Return the upper menu?(Y or N):")
                        if flag_second_return == 'N':
                            for menu in second_menu1["third_menu2"]:
                                print(menu)
                            flag_second_return = 'Y' #重置第二级返回标志，使程序继续运行
                    else:
                        print("You have chosen the third menu3:")
                        flag_second_return = input("Return the upper menu?(Y or N):")
                        if flag_second_return == 'N':
                            for menu in second_menu1["third_menu3"]:
                                print(menu)
                            flag_second_return = 'Y' #重置第二级返回标志，使程序继续运行
                    flag_first_return = 'Y' #重置第一级返回标志，使程序继续运行
                else:
                    break #跳出第二级菜单，返回第一级
        elif second_menu_num == 2:
            while flag_second_return == 'Y':
                print("You have chosen the second menu2.")
                flag_first_return = input("Return the upper menu?(Y or N):")
                if flag_first_return == 'N':
                    third_menu_num = int(input("third menu number:"))
                    if third_menu_num == 4:
                        print("You have chosen the third menu4:")
                        flag_second_return = input("Return the upper menu?(Y or N):")
                        if flag_second_return == 'N':
                            for menu in second_menu2["third_menu4"]:
                                print(menu)
                            flag_second_return = 'Y'
                    elif third_menu_num == 5:
                        print("You have chosen the third menu5:")
                        flag_second_return = input("Return the upper menu?(Y or N):")
                        if flag_second_return == 'N':
                            for menu in second_menu2["third_menu5"]:
                                print(menu)
                            flag_second_return = 'Y'
                    else:
                        print("You have chosen the third menu6:")
                        flag_second_return = input("Return the upper menu?(Y or N):")
                        if flag_second_return == 'N':
                            for menu in second_menu2["third_menu6"]:
                                print(menu)
                            flag_second_return = 'Y'
                    flag_first_return = 'Y'
                else:
                    break
        else:
            while flag_second_return == 'Y':
                print("You have chosen the second menu3.")
                flag_first_return = input("Return the upper menu?(Y or N):")
                if flag_first_return == 'N':
                    third_menu_num = int(input("third menu number:"))
                    if third_menu_num == 7:
                        print("You have chosen the third menu7:")
                        flag_second_return = input("Return the upper menu?(Y or N):")
                        if flag_second_return == 'N':
                            for menu in second_menu3["third_menu7"]:
                                print(menu)
                            flag_second_return = 'Y'
                    elif third_menu_num == 8:
                        print("You have chosen the third menu8:")
                        flag_second_return = input("Return the upper menu?(Y or N):")
                        if flag_second_return == 'N':
                            for menu in second_menu3["third_menu8"]:
                                print(menu)
                            flag_second_return = 'Y'
                    else:
                        print("You have chosen the third menu9:")
                        flag_second_return = input("Return the upper menu?(Y or N):")
                        if flag_second_return == 'N':
                            for menu in second_menu3["third_menu9"]:
                                print(menu)
                            flag_second_return = 'Y'
                    flag_first_return = 'Y'
                else:
                    break
