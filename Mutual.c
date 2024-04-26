#include <stdio.h>
#include <stdlib.h>

int main() {
    int ns, ncs, timestamp, site;
    printf("Enter number of sites: ");
    scanf("%d", &ns);
    printf("Enter number of sites which want to enter critical section: ");
    scanf("%d", &ncs);

    int ts[ns]; // Array to store timestamps for each site
    int request[ncs]; // Array to store site numbers requesting critical section
    int mp[ncs][2]; // 2D array to store timestamps and corresponding sites

    // Initialize timestamps to 0
    for (int i = 0; i < ns; i++) {
        ts[i] = 0;
    }

    // Input timestamps and sites
    for (int i = 0; i < ncs; i++) {
        printf("\nEnter timestamp: ");
        scanf("%d", &timestamp);
        printf("Enter site number: ");
        scanf("%d", &site);

        ts[site - 1] = timestamp; // Adjust index to match site numbering
        request[i] = site;
        mp[i][0] = timestamp;
        mp[i][1] = site;
    }

    // Display sites and their timestamps
    printf("\nSites and Timestamps:\n");
    for (int i = 0; i < ns; i++) {
        printf("%d %d\n", i + 1, ts[i]);
    }

    // Process requests
    for (int i = 0; i < ncs; i++) {
        printf("\nRequest from site: %d\n", request[i]);
        for (int j = 0; j < ns; j++) {
            if (request[i] != (j + 1)) {
                if (ts[j] > ts[request[i] - 1] || ts[j] == 0)
                    printf("%d Replied\n", j + 1);
                else
                    printf("%d Deferred\n", j + 1);
            }
        }
    }

    // Display sites entering critical section
    printf("\n");
    int c = 0;
    for (int i = 0; i < ncs; i++) {
        printf("Site %d entered Critical Section\n", mp[i][1]);
        if (c == 0)
            printf("\nSimilarly,\n\n");
        c++;
    }

    return 0;
}
