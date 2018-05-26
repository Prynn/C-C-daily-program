1.
    for (i=0;i<n;i++)
            for (j=i+1;j<n;j++)
            if(a[i]<a[j])   exchange;
2.
   for(i=0;i<n;i++)
      for(j=0;j<n-i-1;j++)
        if(a[j]<a[j+1])   exchange;
