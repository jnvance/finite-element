import numpy as np

def tri_p1(x,y,eval_p):
    """
    Linear shape function on triangles, namely p1.

    Input:

    x : one dimensional array of triangle vertices x coords.\n
    y : one dimensional array of triangle vertices y coords.\n
    eval_p: (n,2) array of the n evaluation points. first
            column indicates x-coord, second y-coord.\n

    Output:

    dx_phi : the three x-derivatives.\n
    dy_phi : the three y-derivatives.\n
    phi    : (n,3) array of the three shape funtions ath the n eval points.\n
    surf_e : the triangle area.\n

    Notice: all the quantities are computed on the current element

    """
    # print len(x)
    A = np.column_stack((x,y,[1,1,1]))
    one = np.identity(3)
    coeffs = np.zeros((3,3))
    for i in range(3): # loop over phi_(1..3)
        coeffs[i] = np.linalg.solve(A,one[i])

    eval_p = np.array([eval_p]) # comment out when not testing
    n = len(eval_p) # number of evaluation points
    phi = np.zeros((n,3))
    for i in range(n):
        xi, yi = eval_p[i]
        # xy1 = np.array(eval_p[i].tolist().append(1.0))
        for j in range(3):
            # a, b, c = coeffs[j]
            # phi[i][j] = a * xi + b * yi + c
            phi[i][j] = np.dot(coeffs[j],[xi,yi,1])
            # phi[i][j] = np.dot(coeffs[j],xy1)


    dx_phi, dy_phi, cs = coeffs.transpose()
    surf_e = 1./2. * abs(x[0]*y[2]-x[0]*y[1]+x[1]*y[0]-x[1]*y[2]+x[2]*y[1]-x[2]*y[0] )

    # print dx_phi
    # print dy_phi
    # print phi
    # print surf_e

    return dx_phi,dy_phi,phi[0],surf_e
