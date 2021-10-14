icpc -o queen queentest.cxx \
    -std=c++17 \
    -I${TACC_CATCH2_INC} -L${TACC_CATCH2_LIB} \
    -lCatch2Main -lCatch2

# when editing two files: C-x o goes to the other.
# C-x 0 get rid of this panel
