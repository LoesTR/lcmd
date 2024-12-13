import os
import colorama
import platform

def start():
    print(colorama.Fore.BLUE + "LC" + colorama.Fore.CYAN + "MD" + colorama.Fore.RESET + " Command Line")
    print("Made By" + colorama.Fore.BLUE + " loestr")
    print("lcmdhelp - Shows Custom Commands Built in LCMD")

customcommands = ["neofetch", "reloadlcmd", "lcmdhelp", "exit"]

os.system('title LCMD')
os.system('cls')
start()

def normalcommands(lcmdcommand: str):
    os.system(command)

def commandsforonlylcmd(onlylcmd: str):
    if onlylcmd == "neofetch":
        if platform.system() == "Windows":
            print(colorama.Fore.BLUE + "#####   #####" + colorama.Fore.RESET + " OS : " + colorama.Fore.RED + "W" + colorama.Fore.CYAN + "I" + colorama.Fore.YELLOW + "N" + colorama.Fore.GREEN + platform.release() + colorama.Fore.BLUE + "\n#####   #####\n#####   #####\n\n#####   #####\n#####   #####\n#####   #####\n")
        if platform.system() == "Linux":
                print("Operating System : " + colorama.Fore.BLACK + "LINUX" + platform.release())
    if onlylcmd == "reloadlcmd":
        os.system('C:\Apps\LCMD\lcmd.py')
        exit()
    if onlylcmd == "lcmdhelp":
        print("neofetch - Works As The Linux Package One And its Built in lcmd (only operating system)")
        print("reloadlcmd - Reloads LCMD Command Line")
        print("exit - Closes LCMD")
    if onlylcmd == "exit":
        exit()
while True:
    command = input(colorama.Fore.BLUE + '>' + colorama.Fore.CYAN + '>' + colorama.Fore.RESET + ' ')
    if command in customcommands:
        commandsforonlylcmd(command)
    else:
        normalcommands(command)