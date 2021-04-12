#include<iostream>
#include<string>
using namespace std;
/*
int main()
{
	int n;
	cin>>n;
	string name[n+1], place[n+1];//依序為存放cin時候的名字數量地點 
	int num[n+1];//生物的數量用int整數型來存放
	string temp[n+1][n+1];//整理好的資料，column第0欄：地點, 後面剩下的column都是：生物
	int i, j, k;
	
	for(i=0; i<n; i++)	cin >> name[i] >> num[i] >> place[i]; 
	
	cout<<"-------------------------"<<endl;
	
	//////////將重複的地點放到temp的第0欄//////////
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(place[i]==temp[j][0])//如果地點重複就跳過 
				break;
		}
		if(j>k)		//表示有新的地點 
		{
			temp[j][0] = place[i];
			k++;//地點總數+1 
		}
	}
	
	//////////將同一地點不重複的生物放到temp裡面//////////
	//////////如果生物重複，就跳過並且對他的儲存參數+1//////////
	//程式碼大致上跟上面儲存重複地點的方式大同小異
	//備註: temp共有k個欄位是有放東西的，然後總共有n+1個欄位
	
	int m = 1, s = 1;//m從一開始，作為存放生物名字的地方
	int a;
	int sum[k][n+1];//儲存動物數量的一維陣列，總共有k個地點和最多n種動物
	for(i=1; i<=k; i++)//在儲存好的不同地點中
	{
		cout << temp[i][0] << ": ";
		for(j=0; j<n; j++)//將input的所有資料依序跟重複的地點比對
		{
			//所有的input都跟temp的重複地點比較一次，只要input的地點跟temp重複
			//就把input的name丟掉temp這個二維陣列裡面
			if(temp[i][0] == place[j])//如果地點重複(就是連連看有連線的意思)
			{
				for(a=1; a<=m; a++)//依序檢查存放生物的位置有沒有跟現在準備要丟進來的生物名重複
				{
					if(name[j] != temp[i][a])//如果準備要丟進來的名字不等於已經存在二維陣列temp裡面的任何一個名字
					{
						temp[i][m] = name[j];//那就把這個新的生物名字丟到儲存用的二維陣列temp裡面			
						s++;//該地點的生物總數+1//m放在這個for迴圈裡面會有問題，所以放一個s來實現在這個for迴圈裡放m++的功能			
						continue;//當判斷為新的生物名後，它會新增到temp裡面，代表任務完成，直接跳出for迴圈 
					}
					if(name[j] == temp[i][a])//如果生物名字相同
					{
						break;//直接跳出這個for迴圈
					}
				}
				//m的起始值為1，每發現同地點有新的生物，就m++
				//同一個地點沒有重複的生物總數為m-1	
				if(s > m)	m = s;
				
			}
		}
		
		int b;
		for(b=1; b<m; b++)
		{
			if(b==1)
			{
				cout << temp[i][b] << " " ;
			}
			else
			{
				cout << ", " << temp[i][b] << " "  ;//輸出生物名字跟數量
			}
			
		}
		cout << endl;
		
		//每做完一個地點的名字存放，就把m重新assign為1，以利下一個地點繼續做同樣的事
		m = 1;
		s = 1;
	}
}
*/
int main()
{
	int i,j,g,n,k,m,h,a;
	cin>>n;
	string animal[n+1],place[n+1],total[n+1],animalsort[n+1],placesort[n+1],dif[n+1],combine[n+1][n+1];
	int num[n],flag[n],sum[n],count[n][n];
	for(i=0;i<n;i++)
	{
		cin>>animal[i]>>num[i]>>place[i];
		flag[i]=0;
		sum[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			count[i][j]=0;
		}
	}
	
	/*將重複地點從place整理出來放到placesort*/ 
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(place[i]==placesort[j])
				break;
		}
		if(j>k)
		{
			placesort[k]=place[i];
			k++;
		}
	}


	
	m=0;
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			if(placesort[i]==place[j])
			{
				combine[m][0]=place[j];
				combine[m][1]=animal[j];
				m++;
			}
		}	

	} 

	for(i=0;i<k;i++)//k = 3
	{
		h=0;
		a=0;
		cout<<placesort[i]<<" : ";
		for(j=0;j<m;j++)
		{
			h=0;
			if(placesort[i]==combine[j][0])//如果地點相同 
			{
				for(g=0;g<m;g++)//m = 7 
				{
					if(combine[j][1]==animal[g]&&combine[j][0]==place[g])//如果動物名字相同且地點相同 
					{
						h+=num[g];//數字總和到h裡面 
						num[g]=0;//加過的數字歸零 
						
					}
				}
			}
			if(h!=0)
			{
				total[a]=combine[j][1];
				flag[a]=h;
				a++;
			} 
		}
		for(j=0;j<a;j++)
		{
			if(j==0)
				cout<<total[j]<<" "<<flag[j];
			else 
				cout<<", "<<total[j]<<" "<<flag[j];
		}
		cout<<endl;
	}
}







