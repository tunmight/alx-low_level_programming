#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

void print_error(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(98);
}

void print_elf_header(Elf64_Ehdr *header) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for(int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", header->e_type == ET_NONE ? "NONE (No file type)" :
                                                       header->e_type == ET_REL ? "REL (Relocatable file)" :
                                                       header->e_type == ET_EXEC ? "EXEC (Executable file)" :
                                                       header->e_type == ET_DYN ? "DYN (Shared object file)" :
                                                       header->e_type == ET_CORE ? "CORE (Core file)" :
                                                       "Unknown");
    printf("  Entry point address:               %#lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        print_error("Failed to open file");
    }

    Elf64_Ehdr header;
    if(read(fd, &header, sizeof(header)) != sizeof(header)) {
        print_error("Failed to read ELF header");
    }

    #include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

void print_error(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(98);
}

void print_elf_header(Elf64_Ehdr *header) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for(int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", header->e_type == ET_NONE ? "NONE (No file type)" :
                                                       header->e_type == ET_REL ? "REL (Relocatable file)" :
                                                       header->e_type == ET_EXEC ? "EXEC (Executable file)" :
                                                       header->e_type == ET_DYN ? "DYN (Shared object file)" :
                                                       header->e_type == ET_CORE ? "CORE (Core file)" :
                                                       "Unknown");
    printf("  Entry point address:               %#lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        print_error("Failed to open file");
    }

    Elf64_Ehdr header;
    if(read(fd, &header, sizeof(header)) != sizeof(header)) {
        print_error("Failed to read ELF header");
    }

    if(memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    print_elf_header(&header);

    close(fd);
    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

void print_error(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(98);
}

void print_elf_header(Elf64_Ehdr *header) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for(int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", header->e_type == ET_NONE ? "NONE (No file type)" :
                                                       header->e_type == ET_REL ? "REL (Relocatable file)" :
                                                       header->e_type == ET_EXEC ? "EXEC (Executable file)" :
                                                       header->e_type == ET_DYN ? "DYN (Shared object file)" :
                                                       header->e_type == ET_CORE ? "CORE (Core file)" :
                                                       "Unknown");
    printf("  Entry point address:               %#lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        print_error("Failed to open file");
    }

    Elf64_Ehdr header;
    if(read(fd, &header, sizeof(header)) != sizeof(header)) {
        print_error("Failed to read ELF header");
    }

    if(memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    print_elf_header(&header);

    close(fd);
    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

void print_error(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(98);
}

void print_elf_header(Elf64_Ehdr *header) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for(int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", header->e_type == ET_NONE ? "NONE (No file type)" :
                                                       header->e_type == ET_REL ? "REL (Relocatable file)" :
                                                       header->e_type == ET_EXEC ? "EXEC (Executable file)" :
                                                       header->e_type == ET_DYN ? "DYN (Shared object file)" :
                                                       header->e_type == ET_CORE ? "CORE (Core file)" :
                                                       "Unknown");
    printf("  Entry point address:               %#lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        print_error("Failed to open file");
    }

    Elf64_Ehdr header;
    if(read(fd, &header, sizeof(header)) != sizeof(header)) {
        print_error("Failed to read ELF header");
    }

    if(memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    print_elf_header(&header);

    close(fd);
    return 0;
}if(memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    print_elf_header(&header);

    close(fd);
    return 0;
}
