# file:CS112-A1-T2-3-20231181.py
# purpose:in this game player choose the num of coins or make the program choose it randomly and the 2 players take coins and
# who takes the last coin wins
# author:mohrael mourad lotfy demian
# iD: 20231181
# we have two options for the user to choose from them :the random choice and to input the number of coins
print("welcome to our game")
x = " player one"
y = "player two"
player = True
print("please choose from 1 and 2 ")
print("1)input the number of coins")
print("2)random choice")
while True:
    try:
        choice = int((input("enter your choice:")))
        if choice not in [1, 2]:
            raise ValueError
        break
    except ValueError:
        print("please choose 1 or 2")
if choice == 1:
    coins = None
    main_coins = coins
    while True:
        try:
            coins = int(input("the coins:"))
            if coins <= 1:
                raise ValueError
            break
        except ValueError:
            print("you must enter a positive integer bigger than one ")
    main_coins = coins
    print(coins > 0)
    while coins > 0:
        if player:
            z = input("the choice of player one :")
            if z.isdecimal():
                z = int(z)
                if (z**0.5) % 1 == 0 and z != main_coins and z <= coins:
                    coins = coins - z
                    print("the reminder is", coins)
                    player = False
                else:
                    print("it is not valid")
            else:
                print("it is not valid please try again")
        else:
            # player two will play
            z = input("the choice of  player two :")

            if z.isdecimal():
                z = int(z)
                if (z**0.5) % 1 == 0 and z <= coins:
                    coins = coins - z
                    print("the reminder is:", coins)
                    player = True
            else:
                print("it is not valid please try again")
elif choice == 2:
    range = [10, 1001]
    import random

    coins = random.randrange(10, 1000)
    main_coins = coins
    print(coins)
    while coins > 0:

        if player:
            # player one will play
            z = input("the choice of player one :")
            if z.isdecimal():
                z = int(z)
                if (z**0.5) % 1 == 0 and z != main_coins and z <= coins:
                    coins = coins - z
                    print("the reminder is:", coins)
                    player = False
                else:
                    print("it is not valid")
            else:
                print("it is not valid please try again")
        else:
            # player two will play
            z = input("the choice of player two 2:")
            if z.isdecimal():
                z = int(z)
                if (z**0.5) % 1 == 0 and z <= coins:
                    coins = coins - z
                    print("the reminder is:", coins)
                    player = True
            else:
                print("it is not valid please try again")
winner = player
if not player == True:
    print("player one is the winner")
else:
    print("player two is the winner")
