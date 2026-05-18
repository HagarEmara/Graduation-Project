//----------------------------------------------------------------------------
// Copyright [2014] [Ztachip Technologies Inc]
//
// Author: Vuong Nguyen
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except IN compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to IN writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include "../../../base/util.h"
#include "../../../base/ztalib.h"
#include "resize.h"
#include "resize.p.img"

// Perform image resize using bicubic interpolation

#define PAD_VALUE 0
#define TILE_DIM_P  (TILE_DIM+TILE_PAD)

extern void mycallback(int);

typedef struct {
   uint32_t input;
   uint32_t output;
   int nchannel;
   uint32_t spu;
   int scale;
   int w;
   int h;
   int x_off;
   int y_off;
   int src_w;
   int src_h;
   int dst_w;
   int dst_h;
   struct {
      uint32_t init;
      uint32_t init2;
      uint32_t scratch;
      int *scale0;
      int *scale1;
      int *scale2;
      int loopstep;
   } ws;
} Request;

typedef struct 
{
   uint32_t input;
   uint32_t output;
   uint32_t temp;
   uint32_t filter[2];
   uint32_t filteri[2];
   int filterLen[2];
   uint32_t spu;
   int nchannel;
   int src_w;
   int src_h;
   int dst_w;
   int dst_h;
   int scale_x;
   int scale_y;
} RequestBoxResize;

// Box resizing horizontally

void box_resize_horizontal(void *_p,int pid) {
   RequestBoxResize *req=(RequestBoxResize *)_p;
   int ch;
   int np;
   int from,to;
   int src_x,src_y,dst_x,dst_y;
   int src_dx,src_dy,dst_dx,dst_dy;
   int fmt=UINT8;
   int src_dx2;
   int src_w,src_h,dst_w,dst_h;
   uint32_t dst_start;
   uint32_t kfunc[BOX_RESIZE_MAX_FILTER]={0,0,3136,3360,3616,
                                          3904,4224,4576};
   np=NUM_PCORE;

   // Resize width wise first

   src_dx=req->scale_x;
   src_dx2=ROUND(src_dx,VECTOR_WIDTH);
   src_dy=VECTOR_WIDTH*NUM_PCORE;
   dst_dx=NUM_THREAD_PER_CORE;
   dst_dy=VECTOR_WIDTH*NUM_PCORE;
   src_w=req->src_w;
   src_h=req->src_h;
   dst_w=req->dst_w;
   dst_h=req->src_h;

   // Split the work between 2 processes...

   if(pid==0) {
      from=0;
      to=(src_h/2);
      to=ROUND(to,src_dy);
      dst_start=0;
   } else {
      from=(src_h/2);
      from=ROUND(from,src_dy);
      to=src_h;
      dst_start=(from/src_dy)*dst_dy;
   }

{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=7;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(0);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((7)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(0),t01=(1),t02=(BOX_RESIZE_MAX_FILTER*NUM_THREAD_PER_CORE-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((67108864)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->filter[0])>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1036317|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(8);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(UINT8<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(0),t01=(1),t02=(NUM_THREAD_PER_CORE-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((67108864)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->filteri[0])>>(((UINT8)&1)));;ZTAM_GREG(19,8,0)=(1036317|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,188,((np)-1),0,0,0,(15),0);

   ztaTaskYield();

   // Resize horizontally first

   for(ch=0;ch < req->nchannel;ch++) {
      // Scan for each channel...
      for(src_y=from,dst_y=dst_start;src_y < to;src_y+=src_dy,dst_y+=dst_dy) {
         for(src_x=0,dst_x=0;src_x < src_w;src_x+=src_dx,dst_x+=dst_dx) {
            
            // Copy input image to pcore memory space...

{{int t00=(0),t01=(1),t02=((np-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((src_dx2/8-1)),t2=t22,t30=(0),t31=(1),t32=(((8)-1)),t3=t32;ZTAM_GREG(6,8,0)=(1*((VECTOR_WIDTH-1)+1)*((src_dx2/8-1)+1)*(((8)-1)+1))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=(((np-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((src_dx2/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(22,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((src_dx2/8-1)+1)*(((8)-1)+1));ZTAM_GREG(13,8,0)=(1*((src_dx2/8-1)+1)*(((8)-1)+1))*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((src_dx2/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(23,8,0)=t10*(1*((src_dx2/8-1)+1)*(((8)-1)+1));ZTAM_GREG(16,8,0)=(1*(((8)-1)+1))*t21;ZTAM_GREG(17,8,0)=(t2);ZTAM_GREG(18,8,0)=(((src_dx2/8-1)+1)-t20)*(1*(((8)-1)+1))-1;ZTAM_GREG(24,8,0)=t20*(1*(((8)-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((((8)-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((src_dx2/8-1)+1)*(((8)-1)+1))+t10*(1*((src_dx2/8-1)+1)*(((8)-1)+1))+t20*(1*(((8)-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((fmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*(t3+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|((fmt)<<5))|((0)<<8);}{int t00=(ch),t01=(1),t02=(ch),t0=(t02-t00),t10=(src_y),t11=(1),t12=(src_y+src_dy-1),t1=(t12-t10),t20=(src_x),t21=(1),t22=(src_x+src_dx2-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(src_h)*(src_w))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((req->nchannel)-t00)*(1*(src_h)*(src_w))-1;ZTAM_GREG(23,8,0)=t00*(1*(src_h)*(src_w));ZTAM_GREG(16,8,0)=(1*(src_w))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((src_h)-t10)*(1*(src_w))-1;ZTAM_GREG(24,8,0)=t10*(1*(src_w));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((src_w)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(src_h)*(src_w))+t10*(1*(src_w))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->input)>>((((fmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),((DP_CONDITION_SRAM_FLUSH)|0));}{{int t00=(0),t01=(1),t02=(np-1),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=((((src_dx2/8-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(8)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=511;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(7,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(6,8,0)=((1))*(1);ZTAM_GREG(11,8,0)=511;ZTAM_GREG(22,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*((1*(8)*(VECTOR_WIDTH)))+(0)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((src_dx2/8-1)-(0)+(1))/(1))*((((8)-1)-(0)+(1))/(1))*(((VECTOR_WIDTH-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1033247|((fmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((np-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((src_dx2/8-1)),t2=t22,t30=(0),t31=(1),t32=(((8)-1)),t3=t32;ZTAM_GREG(16,8,0)=(1*((VECTOR_WIDTH-1)+1)*((src_dx2/8-1)+1)*(((8)-1)+1))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=(((np-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((src_dx2/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(24,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((src_dx2/8-1)+1)*(((8)-1)+1));ZTAM_GREG(6,8,0)=(1*((src_dx2/8-1)+1)*(((8)-1)+1))*t11;ZTAM_GREG(7,8,0)=(t1);ZTAM_GREG(11,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((src_dx2/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(22,8,0)=t10*(1*((src_dx2/8-1)+1)*(((8)-1)+1));ZTAM_GREG(13,8,0)=(1*(((8)-1)+1))*t21;ZTAM_GREG(14,8,0)=(t2);ZTAM_GREG(15,8,0)=(((src_dx2/8-1)+1)-t20)*(1*(((8)-1)+1))-1;ZTAM_GREG(23,8,0)=t20*(1*(((8)-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((((8)-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((src_dx2/8-1)+1)*(((8)-1)+1))+t10*(1*((src_dx2/8-1)+1)*(((8)-1)+1))+t20*(1*(((8)-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((fmt))&1)));;ZTAM_GREG(19,8,0)=(1034269|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(DP_CONDITION_SRAM_FLUSH));}

;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,EXE_FUNC_FIELD((kfunc[req->filterLen[0]-1])),((np)-1),0,EXE_P0_FIELD((kfunc[req->filterLen[0]-1])),EXE_P1_FIELD((kfunc[req->filterLen[0]-1])),(15),EXE_MODEL_FIELD((kfunc[req->filterLen[0]-1])));

            ztaTaskYield();

            // Copy results back to DDR

{{int t00=(0),t01=(1),t02=((np-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((dst_dx/8-1)),t2=t22,t30=(0),t31=(1),t32=(((8)-1)),t3=t32;ZTAM_GREG(16,8,0)=(1*((VECTOR_WIDTH-1)+1)*((dst_dx/8-1)+1)*(((8)-1)+1))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=(((np-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((dst_dx/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(24,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((dst_dx/8-1)+1)*(((8)-1)+1));ZTAM_GREG(6,8,0)=(1*((dst_dx/8-1)+1)*(((8)-1)+1))*t11;ZTAM_GREG(7,8,0)=(t1);ZTAM_GREG(11,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((dst_dx/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(22,8,0)=t10*(1*((dst_dx/8-1)+1)*(((8)-1)+1));ZTAM_GREG(13,8,0)=(1*(((8)-1)+1))*t21;ZTAM_GREG(14,8,0)=(t2);ZTAM_GREG(15,8,0)=(((dst_dx/8-1)+1)-t20)*(1*(((8)-1)+1))-1;ZTAM_GREG(23,8,0)=t20*(1*(((8)-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((((8)-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((dst_dx/8-1)+1)*(((8)-1)+1))+t10*(1*((dst_dx/8-1)+1)*(((8)-1)+1))+t20*(1*(((8)-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((fmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*(t3+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|((fmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(np-1),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=((((dst_dx/8-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(8)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=127;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(12,8,0)=127;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(7,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(6,8,0)=((1))*(1);ZTAM_GREG(11,8,0)=127;ZTAM_GREG(22,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(520+(0)*((1*(8)*(VECTOR_WIDTH)))+(0)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1033245|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),((DP_CONDITION_SRAM_FLUSH)|0));}{{int t00=(ch),t01=(1),t02=(ch),t0=(t02-t00),t10=(dst_y),t11=(1),t12=(dst_y+dst_dy-1),t1=(t12-t10),t20=(dst_x),t21=(1),t22=(dst_x+dst_dx-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(dst_h)*(dst_w))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((req->nchannel)-t00)*(1*(dst_h)*(dst_w))-1;ZTAM_GREG(23,8,0)=t00*(1*(dst_h)*(dst_w));ZTAM_GREG(16,8,0)=(1*(dst_w))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((dst_h)-t10)*(1*(dst_w))-1;ZTAM_GREG(24,8,0)=t10*(1*(dst_w));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((dst_w)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(dst_h)*(dst_w))+t10*(1*(dst_w))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->temp)>>((((fmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((fmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((np-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((dst_dx/8-1)),t2=t22,t30=(0),t31=(1),t32=(((8)-1)),t3=t32;ZTAM_GREG(6,8,0)=(1*((VECTOR_WIDTH-1)+1)*((dst_dx/8-1)+1)*(((8)-1)+1))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=(((np-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((dst_dx/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(22,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((dst_dx/8-1)+1)*(((8)-1)+1));ZTAM_GREG(13,8,0)=(1*((dst_dx/8-1)+1)*(((8)-1)+1))*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((dst_dx/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(23,8,0)=t10*(1*((dst_dx/8-1)+1)*(((8)-1)+1));ZTAM_GREG(16,8,0)=(1*(((8)-1)+1))*t21;ZTAM_GREG(17,8,0)=(t2);ZTAM_GREG(18,8,0)=(((dst_dx/8-1)+1)-t20)*(1*(((8)-1)+1))-1;ZTAM_GREG(24,8,0)=t20*(1*(((8)-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((((8)-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((dst_dx/8-1)+1)*(((8)-1)+1))+t10*(1*((dst_dx/8-1)+1)*(((8)-1)+1))+t20*(1*(((8)-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((fmt))&1)));;ZTAM_GREG(19,8,0)=(1034269|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(DP_CONDITION_SRAM_FLUSH));}
         }
      }
   }
}

// Box resizing vertically...

void box_resize_vertical(void *_p,int pid) {
   RequestBoxResize *req=(RequestBoxResize *)_p;
   int ch;
   int np;
   int from,to;
   int src_x,src_y,dst_x,dst_y;
   int src_dx,src_dy,dst_dx,dst_dy;
   int fmt=UINT8;
   int src_dy2,dst_dy2;
   int src_w,src_h,dst_w,dst_h;
   uint32_t dst_start;
   uint32_t kfunc[BOX_RESIZE_MAX_FILTER]={0,0,3136,3360,3616,
                                          3904,4224,4576};
   np=NUM_PCORE;

   // Resize vertically

   src_dy=req->scale_y;
   src_dy2=ROUND(src_dy,VECTOR_WIDTH);
   src_dx=VECTOR_WIDTH*NUM_PCORE;
   dst_dy=NUM_THREAD_PER_CORE;
   dst_dy2=ROUND(dst_dy,VECTOR_WIDTH);
   dst_dx=VECTOR_WIDTH*NUM_PCORE;
   src_w=req->dst_w;
   src_h=req->src_h;
   dst_w=src_w;
   dst_h=req->dst_h;

   // Split the work between 2 processes

   if(pid==0) {
      from=0;
      to=(src_w/2);
      to=ROUND(to,src_dx);
      dst_start=0;
   } else {
      from=(src_w/2);
      from=ROUND(from,src_dx);
      to=src_w;
      dst_start=(from/src_dx)*dst_dx;
   }
   
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=7;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(0);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((7)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(0),t01=(1),t02=(BOX_RESIZE_MAX_FILTER*NUM_THREAD_PER_CORE-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((67108864)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->filter[1])>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1036317|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(8);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(UINT8<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(0),t01=(1),t02=(NUM_THREAD_PER_CORE-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((67108864)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->filteri[1])>>(((UINT8)&1)));;ZTAM_GREG(19,8,0)=(1036317|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,188,((np)-1),0,0,0,(15),0);

   ztaTaskYield();

   // Resize horizontally first
   for(ch=0;ch < req->nchannel;ch++) {
      // Scan for each channel...
      for(src_x=from,dst_x=dst_start;src_x < to;src_x+=src_dx,dst_x+=dst_dx) {
       
         for(src_y=0,dst_y=0;src_y < src_h;src_y+=src_dy,dst_y+=dst_dy) {
            
            // Copy input image to pcore memory space...

{{int t00=(0),t01=(1),t02=(np-1),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=((((src_dy2-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=(8)*(1);ZTAM_GREG(15,8,0)=511;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(5,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((src_dy2-1)-(0)+(1))/(1))*(((VECTOR_WIDTH-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|((fmt)<<5))|((0)<<8);}{int t00=(ch),t01=(1),t02=(ch),t0=(t02-t00),t10=(src_y),t11=(1),t12=(src_y+src_dy2-1),t1=(t12-t10),t20=(src_x),t21=(1),t22=(src_x+src_dx-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(src_h)*(src_w))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((req->nchannel)-t00)*(1*(src_h)*(src_w))-1;ZTAM_GREG(23,8,0)=t00*(1*(src_h)*(src_w));ZTAM_GREG(16,8,0)=(1*(src_w))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((src_h)-t10)*(1*(src_w))-1;ZTAM_GREG(24,8,0)=t10*(1*(src_w));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((src_w)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(src_h)*(src_w))+t10*(1*(src_w))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->temp)>>((((fmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
            
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,EXE_FUNC_FIELD((kfunc[req->filterLen[1]-1])),((np)-1),0,EXE_P0_FIELD((kfunc[req->filterLen[1]-1])),EXE_P1_FIELD((kfunc[req->filterLen[1]-1])),(15),EXE_MODEL_FIELD((kfunc[req->filterLen[1]-1])));

            ztaTaskYield();

            // Copy results back to DDR

{{int t00=(ch),t01=(1),t02=(ch),t0=(t02-t00),t10=(dst_y),t11=(1),t12=(dst_y+dst_dy2-1),t1=(t12-t10),t20=(dst_x),t21=(1),t22=(dst_x+dst_dx-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(dst_h)*(dst_w))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((req->nchannel)-t00)*(1*(dst_h)*(dst_w))-1;ZTAM_GREG(23,8,0)=t00*(1*(dst_h)*(dst_w));ZTAM_GREG(16,8,0)=(1*(dst_w))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((dst_h)-t10)*(1*(dst_w))-1;ZTAM_GREG(24,8,0)=t10*(1*(dst_w));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((dst_w)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(dst_h)*(dst_w))+t10*(1*(dst_w))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->output)>>((((fmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((fmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(np-1),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=((((dst_dy2-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=(8)*(1);ZTAM_GREG(15,8,0)=127;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(5,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=127;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(520+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((1)>=0)?1:0,(1)&(3),(0));}
         }
      }
   }
}

// Process image box resize request from host

void kernel_resize_exe(
   unsigned int _req_id,
   unsigned int _input,
   unsigned int _output,
   unsigned int _temp,
   unsigned int _filter_0,
   unsigned int _filter_1,
   unsigned int _filteri_0,
   unsigned int _filteri_1,
   int _filterLen_0,
   int _filterLen_1,
   unsigned int _spu,
   int _nchannel,
   int _src_w,
   int _src_h,
   int _dst_w,
   int _dst_h,
   int _scale_x,
   int _scale_y
) 
{
   RequestBoxResize req;
   
   ztaInitPcore(zta_pcore_img);
   ztaInitStream(_spu);
        
   req.input=_input;
   req.output=_output;
   req.temp=_temp;
   req.filter[0]=_filter_0;
   req.filter[1]=_filter_1;
   req.filteri[0]=_filteri_0;
   req.filteri[1]=_filteri_1;
   req.filterLen[0]=_filterLen_0;
   req.filterLen[1]=_filterLen_1;
   req.spu=_spu;
   req.nchannel=_nchannel;
   req.src_w=_src_w;
   req.src_h=_src_h;
   req.dst_w=_dst_w;
   req.dst_h=_dst_h;
   req.scale_x=_scale_x;
   req.scale_y=_scale_y;

   // Resize horizontally 

   ztaDualHartExecute(box_resize_horizontal,&req);
      
   // Then resize vertically

   ztaDualHartExecute(box_resize_vertical,&req);
           
   ztaJobDone(_req_id);
}
