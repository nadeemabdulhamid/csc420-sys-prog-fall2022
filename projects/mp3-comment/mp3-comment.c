#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    uint8_t version[2];
    uint8_t flags;
    uint32_t size;
} ID3v2hdr;

int read_id3v2_header(ID3v2hdr *hdr, FILE* fp) {
    uint8_t buf[3];

    if (fread(buf, 1, 3, fp) != 3) { fprintf(stderr, "error reading header (file id)\n"); return -1; }
    if (strncmp((char*)buf, "ID3", 3) != 0) { return -1; }  

    if (fread(&hdr->version, 1, 2, fp) != 2) { fprintf(stderr, "error reading header (version)\n"); return -1; }
    if (fread(&hdr->flags, 1, 1, fp) != 1) { fprintf(stderr, "error reading header (flags)\n"); return -1; }

    hdr->size = 0;
    for (int i = 0; i < 4; i++) {
        if (fread(buf, 1, 1, fp) != 1) { fprintf(stderr, "error reading header (size)\n"); return -1; }
        hdr->size = (hdr->size << 7) | (buf[0] & 0x7F);
    }

    return 0;
}

int write_id3v2_header(ID3v2hdr *hdrp, FILE* fp) {
    uint8_t buf;

    fwrite("ID3", 1, 3, fp);
    fwrite(&hdrp->version, 1, 2, fp);
    fwrite(&hdrp->flags, 1, 1, fp);

    for (int i = 3; i >= 0; i--) {
        buf = (hdrp->size >> (i * 7)) & 0x7F;
        fwrite(&buf, 1, 1, fp);
    }
    return 0;
}

int write_comm_frame(char* msg, FILE* fp) {
    uint32_t size = 5 + strlen(msg);
    uint16_t flags = 0;

    fwrite("COMM", 1, 4, fp);
    //fwrite(&size, 4, 1, fp);
    for (int i = 3; i >= 0; i--) {
        uint8_t buf = (size >> (i * 8)) & 0xFF;
        fwrite(&buf, 1, 1, fp);
    }

    fwrite(&flags, 2, 1, fp);

    fwrite(&flags, 1, 1, fp);
    fwrite("eng", 1, 3, fp);
    fwrite(&flags, 1, 1, fp);
    fwrite(msg, 1, strlen(msg), fp);
    return 0;
}

int copy_file(FILE* from_fp, FILE* to_fp) {
    char buf[1024];
    size_t n;

    while ( (n = fread(buf, 1, 1024, from_fp)) != 0 ) {
        fwrite(buf, 1, n, to_fp);
    }

    return 0;
}

void process_cmdline(int argc, char *argv[], char** infilename, char**outfilename, char**msg) {
    if (argc != 4) {
        printf("Usage: %s <input-file> <output-file> <comment text>", argv[0]);
        exit(-1);
    }

    *infilename = argv[1];
    *outfilename = argv[2];
    *msg = argv[3];
}

int main(int argc, char *argv[]) {
    char *infname, *outfname, *msg;
    process_cmdline(argc, argv, &infname, &outfname, &msg);

    FILE* ifp = fopen(infname, "rb");
    FILE* ofp = fopen(outfname, "wb");
    ID3v2hdr hdr;

    if (read_id3v2_header(&hdr, ifp) != 0) { exit(-1); }

    printf("%d.%d\nFlags: %x\nSize: %d\n", hdr.version[0], hdr.version[1], hdr.flags, hdr.size);
    if (hdr.version[0] != 3 || hdr.flags != 0) {
        printf("Incompatible file version/flags\n"); 
        exit(-1);
    }

    hdr.size += 15 + strlen(msg);  // 10 bytes TLAN frame header + header for 'Comment' (5 bytes) + actual text
    write_id3v2_header(&hdr, ofp);
    write_comm_frame(msg, ofp);
    copy_file(ifp, ofp);

    fclose(ifp);
    fclose(ofp);
    
    return 0;
}