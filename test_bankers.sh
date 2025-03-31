#!/bin/bash

# Compile the program (assuming it's named `bankers.c`)
gcc -o ./bin/bankers ./os_assign_sem4/ass_007_2.c

# Run the program with predefined inputs (safe case)
echo "Running Safe Sequence Case..."
./bin/bankers <<EOF
4
3
3
2
2
3
0
1
0
2
2
2
2
3
1
0
2
1
3
3
3
3
3
3
3
3
3
3
EOF

echo -e "\n-----------------------------------\n"

# Run the program with predefined inputs (unsafe case)
echo "Running No Safe Sequence Case..."
./bin/bankers <<EOF
4
1
0
2
1
3
1
1
1
2
2
2
2
2
0
0
1
1
1
1
3
2
2
2
2
2
EOF

