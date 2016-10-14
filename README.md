# 2D-K-Mean-Clustering
Implementation of k-mean clustering for two dimensaional data.

Consists of the following two files:

###2dkmean.CPP
This file stored the code for the clustering algorithm that takes in data from the user and displays the cluster at each iteration.
The data is stored in an object of the type node which stored the id and the respective dimensional data. More dimensions can be added
to the structure of the class to incorporate more dimensions. In this case, the dimension is 2 and hence, the distance is calculated
using Eucledian Distance.

###TestIP.txt
This is the input file.

Line 1 - Number of nodes
Line 2 to 15 - The input that has to be clustered.*
Line 16 - Number of Clusters
Line 17 to 20 - Assumed initial Means

*The input entered is for the following data:

| Dimension 1 | Dimension 2 |
| --- | --- |
| 1 | 1 |
| 1.5 | 2 |
| 3 | 4 |
| 5 | 7 |
| 3.5 | 5 |
| 4.5 | 5 |
| 3.5 | 4.5 |

Number of Clusters : 2

Assumed Initial Means:

Mean 1 : 1,1

Mean 2 : 5,7
