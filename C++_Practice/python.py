import random

def choose():
    words=['rohit','gill','virat','iyer','rahul','hardik','jadeja','kuldeep','bhurmh','siraj','shardul']
    pick = random.choice(words)
    return pick
    
def jumble(word):
    jumbled = "".join(random.sample(word, len(word)))
    return jumbled

def thank(p1p, p2p, p1, p2):
    print(p1p, "your score is:", p1)
    print(p2p, "your score is:", p2)
    print("Thank you for playing")
    print("Have a nice day")

def play():
    p1p = input("Player 1, enter your name: ")
    p2p = input("Player 2, enter your name: ")
    p1 = 0
    p2 = 0
    turn = 0
    while True:
        picked_word = choose()
        qn = jumble(picked_word)
        if turn % 2 == 0:
            print("Guess the word with letters:", qn)
            ans = input("What is the word you guessed: ")
            if ans == picked_word:
                p1 = p1 + 1
                print("Your score is", p1)
            else:
                print("Better luck next time. I thought:", picked_word)
                c = input("Press 1 to continue and 0 to quit: ")
                if c == '0':
                    thank(p1p, p2p, p1, p2)
                    break
        else:
            print("Guess the word with letters:", qn)
            ans = input("What is the word you guessed: ")
            if ans == picked_word:
                p2 = p2 + 1
                print("Your score is", p2)
            else:
                print("Better luck next time. I thought:", picked_word)
                c = input("Press 1 to continue and 0 to quit: ")
                if c == '0':
                    thank(p1p, p2p, p1, p2)
                    break
        turn = turn + 1

# Call the play function to start the game
play()