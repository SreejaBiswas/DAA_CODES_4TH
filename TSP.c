#include<stdio.h>
#include<limits.h>


void Winit(int n, int W[n][n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			W[i][j]=0;
		}
	}
}

void arrinit(int n, int arr[n]){
	int i;
	for(i=0;i<n;i++){
		arr[i]=0;
	}
}

void display(int n, int W[n][n]){
	int i,j;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if(W[i][j] == 9999)
			printf("INF  ");
			else 
			printf("%d  ",W[i][j]);
		}
		printf("\n");
	}
}

void Wmatrix(int n, int W[n][n]){
	int i,j;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if(i!=j && W[i][j]==0){
				W[i][j]=9999;
			}
		}
	}
}

void Dinit(int n, int y, int D[n][y]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<(1 << n);j++){
			D[i][j]=0;
		}
	}
}


int tsp(int i, int y, int z, int k, int W[z][z], int D[z][k]){
	int temp,j,res=1000000;

	if (y == ((1 << i) | 3))
        	return W[1][i];
    
    	if (D[i][y] != 0)
        	return D[i][y];


    	for (j = 1; j < z; j++)
        	if ((y & (1 << j)) && j != i && j != 1){
            		temp = (tsp(j, y & (~(1 << i)), z, k, W, D) + W[j][i]);
            		if(temp<res){
            			res=temp;
            		}
            	}

    	return D[i][y] = res;
}

int calctsp(int z, int k, int W[z][z], int D[z][k]){
	int i,temp,ans = 1000000;
	for (i = 1; i < z; i++) {
        	temp = tsp(i, (k - 1), z, k, W, D) + W[i][1];
        	if (temp < ans) {
            		ans = temp;
        	}
    	}
	return ans;
}

void showpath(int ans, int z, int cur_vertex, int cur_length, int visit_count, int path_index, int visited[z], int path[z], int W[z][z]){
	int cycle_len,i;

	visited[cur_vertex] = 1;  
    	path[path_index] = cur_vertex; 
    	
    	if(visit_count == (z-1) && W[cur_vertex][1] > 0){
        	cycle_len = cur_length + W[cur_vertex][1];  
        	if(cycle_len == ans){
            		for(i=1;i<z;i++){
                		printf("%d-> ", path[i]);  
            		}
            	printf("%d ", path[1]);  
            	printf("\n");
        	}
    	}

    	for(i=1;i<z;i++) {
        	if (!visited[i] && W[cur_vertex][i] > 0) {
            		showpath(ans,z,i,cur_length + W[cur_vertex][i], visit_count + 1, path_index + 1,visited,path,W);
        	}
    	}
        visited[cur_vertex] = 0;  
}


int main(){
	int n,u,v,k,z,y,S;
	
	FILE *fptr = fopen("tsp2.txt","rt");
	if(fptr==NULL){
		printf("File doesn't exist!!");
	}
	fscanf(fptr,"%d",&n)!=EOF;
	z=n+1;
	y=(1 << z);
	int W[z][z];
	Winit(z,W);
	
	while (fscanf(fptr, "%d%d%d", &u, &v, &k)!=EOF){
		W[u][v]=k;
	}
	
	fclose(fptr);
	
	Wmatrix(z,W);
	
	printf("\nWeight Matrix:\n");
	display(z,W);
	
	int D[z][y];
	Dinit(z,y,D);
	
	int visited[z],path[z];
	arrinit(z,visited);
	arrinit(z,path);
	
		
	int min_cost=calctsp(z,y,W,D);
	printf("\nMinimun Cost: %d", min_cost);
	printf("\nOptimal Path:\n");
	showpath(min_cost,z,1,0,1,1,visited,path,W);

}

8
1 2 5
1 4 6
1 6 4
1 8 8
2 1 5
2 3 2
2 4 4
2 5 3
3 2 2
3 4 1
4 1 6
4 2 4
4 3 1
4 5 7
5 2 3
5 4 7
5 8 4
5 7 6
6 1 4
6 7 3
7 6 3
7 8 2
7 5 6
8 1 8
8 5 4
8 7 2

