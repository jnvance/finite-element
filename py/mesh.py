import numpy as np

def read_msh(filename):

    x = np.array([])
    y = np.array([])
    topo = np.array([], dtype=int)
    nodes = np.array([], dtype=int)
    b_nodes = np.array([], dtype =int)


    f = open(filename, 'r')

    for line in f:
        if line[0] ==  '$':
            # print ("this is useless")
            None
        else:

             l = map(float,line.split())
             #print(map(float,line.split()))
             if len(l) == 4:
                 x = np.append(x,l[1])
                 y = np.append(y,l[2])

             if len(l) == 8:
                    #print np.array(l[5:8])
                    l = map(int, l)
                    topo = np.append(topo,l[5:8])
             if len(l) == 7:
                    l = map(int, l)
                    elements = l[5:]
                    for i in elements:
                        if i-1 not in b_nodes:
                            b_nodes = np.append(b_nodes, i-1)



    f.close()
    topo = np.reshape(topo,(len(topo)/3,3))
    topo = topo - 1
    # print topo

    r_id = 0
    for row in topo:
        ck =      (x[row[1]]-x[row[0]])*(y[row[2]]-y[row[0]])
        ck = ck - (x[row[2]]-x[row[0]])*(y[row[1]]-y[row[0]])
        if ck < 0:
            topo[r_id,:] = np.array([[row[0],row[2],row[1]]])
        r_id+=1

    # print r_id
    return topo , x , y , nodes , b_nodes
