import numpy as np


def getTotalEfficiency(skill):
    keys = np.arange(len(skill))
    values = skill
    hash_map = dict(zip(keys, values))
    teams = []
    s = []
    for i,j in hash_map.items():
        for n in range(i+1,len(skill)):
            # print(n)
            teams.append([j,hash_map[n]])
            s.append(sum(teams[-1]))
            unique_sum = dict(zip(s,teams))
    # -----------------------------------------
    Unique_teams = [list(y) for y in set(frozenset(y) for y in teams)]
    # -----------------------------------------
    # find teams with only two members.
    # find the sum efficiency of unique teams.
    unique_eff = []
    complete_team = []
    for k in unique_sum.keys():
        for i in range(len(Unique_teams)):
            if sum(Unique_teams[i]) == k:
                unique_eff.append(k)
                if len(Unique_teams[i]) == 2:
                    complete_team.append(Unique_teams[i])
    # -----------------------------------------
    # find possible sum efficiencies which shows narrows down the possible teams.
    possible_sums = [x for x in unique_eff if unique_eff.count(x) > 1]
    count_sums = list(set(possible_sums))
    # -----------------------------------------
    counts = []
    for i in range(len(count_sums)):
        counts.append(possible_sums.count(count_sums[i]))
    max_count = np.max(counts)
    max_ind = counts.index(max_count)
    group_sums = count_sums[max_ind]
    # -----------------------------------------
    # find groups that have sum efficiencies equal to "count_sums"
    Groups = []
    for i in range(len(complete_team)):
        if sum(complete_team[i]) == group_sums:
            Groups.append(complete_team[i])
    # -----------------------------------------
    # find efficiencies of each team
    effic = []
    for i in range(len(Groups)):
        effic.append(Groups[i][0]*Groups[i][1])
    sum_effic = sum(effic)
    # -----------------------------------------
    return sum_effic


if __name__ == '__main__':
    
    print("--- members count ---")
    skill_count = int(input().strip())
    print("--- members efficiency ---")
    skill = []

    for _ in range(skill_count):
        skill_item = int(input().strip())
        skill.append(skill_item)

    result = getTotalEfficiency(skill)
    print("==========")
    print(str(result))
    print("==========")


