def combSort(arr):
	n = len(arr)
	gap = n
	# su dung de ghi nhan buoc lap khong co phep 
	#hoan doi nao dc thuc hien ==> mang da sap xep xong
	sorted = False
	shrink = 1.3

	while(gap > 1 or sorted == False):
		gap = int(gap/shrink)
		if(gap < 1): 
			sorted = True
		for i in range(0, n):
    			if arr[i] > arr[i+gap]:
					arr[i], arr[i+gap] = arr[i+gap], arr[i]
					sorted = False
	
if __name__ == '__main__':
    	n = int(input())
		arr = []





	



    			
