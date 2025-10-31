#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 5     // Expanded from 3 to 5
#define MAX_RESOURCES 5 // Expanded from 3 to 5
#define MAX_NAME_LEN 20

typedef enum {
    READ = 1,
    WRITE = 2,
    EXECUTE = 4
} Permission;

// User and Resource Definitions
typedef struct {
    char name[MAX_NAME_LEN];
} User;

typedef struct {
    char name[MAX_NAME_LEN];
} Resource;

// ACL Entry
typedef struct {
    char userName[MAX_NAME_LEN];
    int permissions;
} ACLEntry;

typedef struct {
    Resource resource;
    ACLEntry aclEntries[MAX_USERS];
    int aclCount;
} ACLControlledResource;

// Capability Entry
typedef struct {
    char resourceName[MAX_NAME_LEN];
    int permissions;
} Capability;

typedef struct {
    User user;
    Capability capabilities[MAX_RESOURCES];
    int capabilityCount;
} CapabilityUser;

// Utility Functions
void printPermissions(int perm) {
    int print = 0;
    if (perm & READ) {
        printf("READ");
        print = 1;
    }
    if (perm & WRITE) {
        if (print) printf(", ");
        printf("WRITE");
        print = 1;
    }
    if (perm & EXECUTE) {
        if (print) printf(", ");
        printf("EXECUTE");
    }
}

int hasPermission(int userPerm, int requiredPerm) {
    return (userPerm & requiredPerm) == requiredPerm;
}

// ACL System
void checkACLAccess(ACLControlledResource *res, const char *userName, int perm) {
    for (int i = 0; i < res->aclCount; i++) {
        if (strcmp(res->aclEntries[i].userName, userName) == 0) {
            printf("ACL Check: User %s requests ", userName);
            printPermissions(perm);
            printf(" on %s: ", res->resource.name);
            
            if (hasPermission(res->aclEntries[i].permissions, perm)) {
                printf("Access GRANTED\n");
            } else {
                printf("Access DENIED\n");
            }
            return;
        }
    }

    printf("ACL Check: User %s has NO entry for resource %s: Access DENIED\n", 
           userName, res->resource.name);
}

// Capability System
void checkCapabilityAccess(CapabilityUser *user, const char *resourceName, int perm) {
    for (int i = 0; i < user->capabilityCount; i++) {
        if (strcmp(user->capabilities[i].resourceName, resourceName) == 0) {
            printf("Capability Check: User %s requests ", user->user.name);
            printPermissions(perm);
            printf(" on %s: ", resourceName);
            
            if (hasPermission(user->capabilities[i].permissions, perm)) {
                printf("Access GRANTED\n");
            } else {
                printf("Access DENIED\n");
            }
            return;
        }
    }

    printf("Capability Check: User %s has NO capability for %s: Access DENIED\n",
           user->user.name, resourceName);
}

// Optional Enhancement Functions
void addACLEntry(ACLControlledResource *res, const char *userName, int perm) {
    if (res->aclCount < MAX_USERS) {
        strcpy(res->aclEntries[res->aclCount].userName, userName);
        res->aclEntries[res->aclCount].permissions = perm;
        res->aclCount++;
    }
}

void addCapability(CapabilityUser *user, const char *resourceName, int perm) {
    if (user->capabilityCount < MAX_RESOURCES) {
        strcpy(user->capabilities[user->capabilityCount].resourceName, resourceName);
        user->capabilities[user->capabilityCount].permissions = perm;
        user->capabilityCount++;
    }
}

int main() {
    // Sample users and resources
    User users[MAX_USERS] = {{"Alice"}, {"Bob"}, {"Charlie"}, {"David"}, {"Eva"}};
    Resource resources[MAX_RESOURCES] = {{"File1"}, {"File2"}, {"File3"}, {"File4"}, {"File5"}};

    // ACL Setup
    ACLControlledResource aclResources[MAX_RESOURCES];
    
    // Initialize and Add ACL entries
    for (int i = 0; i < MAX_RESOURCES; i++) {
        strcpy(aclResources[i].resource.name, resources[i].name);
        aclResources[i].aclCount = 0;
    }
    
    addACLEntry(&aclResources[0], "Alice", READ | WRITE | EXECUTE);
    addACLEntry(&aclResources[0], "Bob", READ);
    addACLEntry(&aclResources[1], "Bob", WRITE | EXECUTE);
    addACLEntry(&aclResources[2], "Charlie", READ | EXECUTE);
    addACLEntry(&aclResources[3], "David", READ | WRITE);
    addACLEntry(&aclResources[4], "Eve", READ);

    // Capability Setup
    CapabilityUser capUsers[MAX_USERS];
    
    // Initialize and Add capabilities
    for (int i = 0; i < MAX_USERS; i++) {
        strcpy(capUsers[i].user.name, users[i].name);
        capUsers[i].capabilityCount = 0;
    }

    addCapability(&capUsers[0], "File1", READ | WRITE | EXECUTE);
    addCapability(&capUsers[1], "File1", READ);
    addCapability(&capUsers[1], "File2", WRITE);                  
    addCapability(&capUsers[2], "File3", EXECUTE);
    addCapability(&capUsers[3], "File4", READ | WRITE);
    addCapability(&capUsers[4], "File5", READ);

    printf("=== ACL ACCESS CONTROL TESTS ===\n");
    
    // Test ACL
    checkACLAccess(&aclResources[0], "Alice", READ);
    checkACLAccess(&aclResources[0], "Bob", WRITE);
    checkACLAccess(&aclResources[0], "Charlie", READ);
    checkACLAccess(&aclResources[1], "Bob", EXECUTE);
    checkACLAccess(&aclResources[3], "David", WRITE);
    checkACLAccess(&aclResources[4], "Eve", EXECUTE);
    checkACLAccess(&aclResources[2], "Alice", READ);
    checkACLAccess(&aclResources[4], "David", READ);

    printf("\n=== CAPABILITY ACCESS CONTROL TESTS ===\n");
    
    // Test Capability
    checkCapabilityAccess(&capUsers[0], "File1", WRITE);
    checkCapabilityAccess(&capUsers[1], "File1", WRITE);    
    checkCapabilityAccess(&capUsers[2], "File2", READ);
    checkCapabilityAccess(&capUsers[1], "File2", WRITE);
    checkCapabilityAccess(&capUsers[3], "File4", READ);
    checkCapabilityAccess(&capUsers[4], "File5", EXECUTE);
    checkCapabilityAccess(&capUsers[0], "File3", READ);
    checkCapabilityAccess(&capUsers[4], "File4", WRITE);

    return 0;
}
