#Assembly Line Scheduling using Dynamic Programming for 2 lines
#31/10/2021
#Author : Yagnesh Bhadiyadra

 

if __name__ == "__main__":
    n_station = input('Enter number of stations : ')
    n_station = int(n_station)
    Entry_1, Entry_2 = input('Enter space saparated entry times : ').split()
    Exit_1, Exit_2 = input('Enter space saparated exit times : ').split()
    Entry_1 = int(Entry_1)
    Entry_2 = int(Entry_2)
    Exit_1 = int(Exit_1)
    Exit_2 = int(Exit_2)
    S1 = [None]*n_station
    S2 = [None]*n_station
    print('Enter station cost values for Line 1 from 1 to', n_station, '(Enter after each cost)')
    for i in range(n_station):
        S1[i] = input()
        S1[i] = int(S1[i])
    
    print('Enter station cost values for Line 2 values from 1 to', n_station, '(Enter after each cost)')
    for i2 in range(n_station):
        S2[i2] = input()
        S2[i2] = int(S2[i2])    
    
    print('Enter Travelling time')
    travel_time = []

    for i3 in range(0, n_station - 1):
        print("Enter travelling time of station", (i3 + 1), "of line 1 to station", (i3+2), "of line 2 :", end = " ")
        travel_1_2 = input()
        travel_1_2 = int(travel_1_2)
        print("Enter travelling time of station", (i3 + 1), "of line 2 to station", (i3+2), "of line 1 :", end = " ")
        travel_2_1 = input()
        travel_2_1 = int(travel_2_1)
        travel_time.append([travel_1_2, travel_2_1])


    S1[0] = Entry_1 + S1[0]
    S2[0] = Entry_2 + S2[0]
    print('printing travel time')
    print(travel_time)
    track_path = []
    
    for i4 in range (1, n_station):
        if( (S1[i4 - 1] + S1[i4]) <= (S2[i4 - 1] + travel_time[i4-1][1] + S1[i4]) ):
            S1[i4] =  (S1[i4 - 1] + S1[i4])
            track_s1 = 1
        else:
            S1[i4] =  S2[i4 - 1] + travel_time[i4-1][1] + S1[i4]
            track_s1 = 2
        if ((S2[i4 - 1] + S2[i4]) <= S1[i4 - 1] + travel_time[i4-1][0] + S2[i4]):
            S2[i4] = S2[i4 - 1] + S2[i4]
            track_s2 = 2 
        else:
            S2[i4] =  S1[i4 - 1] + travel_time[i4-1][0] + S2[i4]
            track_s2 = 1        
        track_path.append([track_s1, track_s2])
    
    print('table')
    print(S1)
    print(S2)

    if( (S1[n_station-1] + Exit_1) <= (S2[n_station-1] + Exit_2) ):
        total_time = S1[n_station - 1] + Exit_1
        start_path = 1
    else:
        total_time = S2[n_station - 1] + Exit_2
        start_path = 2
    
    print("total cost/time =", total_time)


    #################  Printing path  #########################
    print("From final exit, backtrack to station", n_station, "of line", start_path)
    for i in range(n_station - 2, -1, -1):
        print("From station", (i + 2), "of line", start_path, "backtrack to station", (i + 1), "through line", track_path[i][start_path - 1])
        start_path = track_path[i][start_path-1]
