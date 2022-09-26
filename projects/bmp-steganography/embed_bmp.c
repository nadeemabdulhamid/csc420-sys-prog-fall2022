#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#pragma pack(push, 1)

typedef struct {             // Total: 54 bytes
  uint16_t  type;             // Magic identifier: 0x4d42
  uint32_t  size;             // File size in bytes
  uint16_t  reserved1;        // Not used
  uint16_t  reserved2;        // Not used
  uint32_t  offset;           // Offset to image data in bytes from beginning of file (54 bytes)
  uint32_t  dib_header_size;  // DIB Header size in bytes (40 bytes)
  int32_t   width_px;         // Width of the image
  int32_t   height_px;        // Height of image
  uint16_t  num_planes;       // Number of color planes
  uint16_t  bits_per_pixel;   // Bits per pixel
  uint32_t  compression;      // Compression type
  uint32_t  image_size_bytes; // Image size in bytes
  int32_t   x_resolution_ppm; // Pixels per meter
  int32_t   y_resolution_ppm; // Pixels per meter
  uint32_t  num_colors;       // Number of colors  
  uint32_t  important_colors; // Important colors 
} BMPHeader;

#pragma pack(pop)


int read_bmp(FILE* bfp, BMPHeader *header) {
    int hdr_sz = sizeof(BMPHeader);    
    fseek(bfp, 0, SEEK_SET);
    if (fread(header, hdr_sz, 1, bfp) != 1 ) { fprintf(stderr, "error reading header\n"); return -1; }

    printf("header size: %u\n", hdr_sz);
    printf("type: %X\n", header->type);
    printf("file size: %u\n", header->size);
    printf("offset: %u\n", header->offset);
    printf("bpp: %u\n", header->bits_per_pixel);
    printf("%u x %u\n", header->width_px, header->height_px);
    printf("colors: %d\n", header->width_px * header->height_px * 3);

    return 0;
}


int embed_uint32(uint32_t val, FILE* fp, uint32_t offset) {
    char d;
    int i;

    for (i = 0; i < 32; i++) {
        fseek(fp, offset, SEEK_SET);
        int bit_val = (1 << i) & val  ?  1 : 0;
        if (fread(&d, 1, 1, fp) != 1) { printf("Read failed!"); exit(-1); }
        d = (d & ~1) | bit_val;
        fseek(fp, offset, SEEK_SET);
        if (fwrite(&d, 1, 1, fp) != 1) { printf("Write failed"); exit(-1); }
        //printf("Wrote %d to %d\n", bit_val, offset);
        offset++;
    }

    return offset;
}

int embed_uint8(uint8_t val, FILE* fp, uint32_t offset) {
    char d;
    int i;

    for (i = 0; i < 8; i++) {
        fseek(fp, offset, SEEK_SET);
        int bit_val = (1 << i) & val  ?  1 : 0;
        if (fread(&d, 1, 1, fp) != 1) { printf("Read failed!"); exit(-1); }
        d = (d & ~1) | bit_val;
        fseek(fp, offset, SEEK_SET);
        if (fwrite(&d, 1, 1, fp) != 1) { printf("Write failed"); exit(-1); }
        //printf("Wrote %d to %d\n", bit_val, offset);
        offset++;
    }

    return offset;
}


int main(int argc, char const *argv[])
{
    BMPHeader header;
    const char* MSG = "Tell me and I forget. Teach me and I remember. Involve me and I learn.";
    uint32_t len;

    FILE* fp = fopen( "dig10k_flowers.bmp", "rb+");
    //FILE* fp = fopen( "read_bmp.c", "rb");
    
    if (fp == NULL) {
        fprintf(stderr, "error opening file\n"); 
        exit(-1);
    }

    if (read_bmp(fp, &header)) { exit(-1); }

    printf("length of text: %lu\n", strlen(MSG));
    printf("bits of message: %lu\n", strlen(MSG) * sizeof(char) * 8);

    uint32_t current_offset = embed_uint32(strlen(MSG), fp, header.offset);
    printf("offset 1: %d\n", current_offset);

    for (int i = 0; i < strlen(MSG); i++) {
        current_offset = embed_uint8(MSG[i], fp, current_offset);
    }
    
    fclose(fp);
    return 0;
}
