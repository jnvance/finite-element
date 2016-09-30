import numpy as np

if __name__ == "__main__":
    
    a = np.reshape(np.arange(16.),(4,4))
    
    print(a);
    
    a.astype('float64').tofile("np_array")
    
