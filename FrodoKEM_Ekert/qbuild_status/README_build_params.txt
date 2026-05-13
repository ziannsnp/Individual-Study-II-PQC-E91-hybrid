Build examples:

make print-config
make

make N=2 q=32768 ERR=12
make PARAM_N=2 PARAM_Q=32768 PARAM_ERR=12

make clean
make N=3 q=32768 ERR=4

Meaning:
- N or PARAM_N     = matrix dimension
- q or PARAM_Q     = modulus
- ERR or PARAM_ERR = search/error range used by brute-force attack
