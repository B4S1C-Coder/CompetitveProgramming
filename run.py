import sys
import os
import argparse
from pathlib import Path
import subprocess

CWD = os.getcwd()

parser = argparse.ArgumentParser(prog="oggy")
parser.add_argument("-rft", "--refresh-tags", action="store_true", help="Refresh neovim tags")
parser.add_argument("-git", "--github", action="store_true", help="Github Actions")
parser.add_argument("-gbr", "--github-branch", type=str, help="Github branch or origin to push to")
parser.add_argument("-gcm", "--github-commit-message", type=str, help="Github commit message")

args = parser.parse_args()

if args.refresh_tags:
    path = Path(CWD) / ".vim/tags"
    if not path.exists():
        print(f"'{path}' not found, creating...")
        path.parent.mkdir(parents=True, exist_ok=True)
        path.touch()
        print("Created.")
    
    subprocess.run(
        "find . -type f -not -path '*/.git/*' -not -path '*/node_modules/*' | xargs file --mime-type | grep 'text/' | cut -d: -f1 | xargs ctags -f .vim/tags",
        shell=True,
        check=True,
    )
    print("Updated tags")

if args.github:
    branch = args.github_branch or input("Specify branch or origin> ").strip()
    message = args.github_commit_message or input("Commit message> ").strip()

    print(f"Branch -> {branch} <==> Changes -> . <==> Message -> {message}")
    subprocess.run("git status", shell=True, check=True)
    choice = input("Proceed with this operation? (y/any other key)> ").strip().lower()

    if choice == "y":
        subprocess.run("git add .", shell=True, check=True)
        subprocess.run(f"git commit -m '{message}'", shell=True, check=True)
        subprocess.run(f"git push origin {branch}", shell=True, check=True)
    else:
        print("Aborted.")

# find . -type f -not -path '*/.git/*' -not -path '*/node_modules/*' | xargs file --mime-type | grep 'text/' | cut -d: -f1 | xargs ctags -f .vim/tags


#CPP_SOURCE_FILE = sys.argv[1]
#COMMAND = f"g++ -O3 -o ./bin/{CPP_SOURCE_FILE.split(os.sep)[-1]}.x -Wall {CPP_SOURCE_FILE} && ./bin/{CPP_SOURCE_FILE.split(os.sep)[-1]}.x"

# print(f"RUNNING ---> {COMMAND}\n\n-----------------------------OUTPUT-----------------------------\n")
# os.system(COMMAND)
