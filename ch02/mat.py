'''
algorithms from section 2.5, Rosen's DMA 5th
    by Yue Wang 30.11.2014
'''

'''
A simple matrix
'''
class Matrix:
    def __init__(self,data):
        self.data_ = data
    def write(self):
        for row in self.data_:
            for elem in row:
                print(elem, end=' ')
            print()
