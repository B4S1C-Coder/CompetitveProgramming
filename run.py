import sys
import os

CPP_SOURCE_FILE = sys.argv[1]
COMMAND = f"g++ -O3 -o ./bin/{CPP_SOURCE_FILE.split(os.sep)[-1]}.x -Wall {CPP_SOURCE_FILE} && ./bin/{CPP_SOURCE_FILE.split(os.sep)[-1]}.x"

print(f"RUNNING ---> {COMMAND}\n\n-----------------------------OUTPUT-----------------------------\n")
os.system(COMMAND)