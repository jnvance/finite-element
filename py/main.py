import numpy as np

from mesh import *
from basis_func import *
from assemble import *

from viewer import *

def clear_rows(A,b_nodes):
    """ code to clear rows """
    n = A.shape[0]
    for i in b_nodes:
        for j in range(n):
            if i != j:
                A[i,j] = 0
    return A

if __name__ == "__main__":
    # some test codes for clear_rows
    # A = np.random.random((6,6))
    # b_nodes = [1,3,5]
    # print A
    # A = clear_rows(A,b_nodes)
    # print A

    topo , x , y , nodes , b_nodes = read_msh("mesh/square.msh")

    A = gradu_gradv(topo,x,y)
    F = f_v(topo,x,y)

    A = clear_rows(A,b_nodes)
    F[b_nodes] = 0

    z = np.linalg.solve(A,F)
    plot_sol_p1(x,y,z,topo)
