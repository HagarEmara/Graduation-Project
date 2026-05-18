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

#include "../../../base/ztalib.h"
#include "gaussian.h"
#include "gaussian.p.img"
#include "gaussian.h"

// Kernel to perform gaussian blurring 
// Refer to https://en.wikipedia.org/wiki/Gaussian_blur

extern void mycallback(int);

typedef struct {
   uint32_t input;
   uint32_t output;
   uint32_t kernel;
   int nchannel;
   int ksz;
   int w;
   int h;
   int src_w;
   int src_h;
   int x_off;
   int y_off;
   int dst_w;
   int dst_h;
} Request;

static void iconv(void *_p,int pid) {
   Request *req=(Request *)_p;
   int from,to;
   int dx,dx2,dy;
   int dxcnt,dycnt;
   int h,pad;
   int ch,inputLen;
   uint32_t input,output;
   int x,y,cnt;
   int x_off,y_off;

   x_off=req->x_off;
   y_off=req->y_off;
   pad=(req->ksz/2);
   dx2=NUM_PCORE*TILE_DX_DIM;
   dx=NUM_PCORE*TILE_DX_DIM-pad;
   dy=TILE_DY_DIM*VECTOR_WIDTH;
   dxcnt=(req->w+dx-1)/dx;
   dycnt=(req->h+dy-1)/dy;
   h=(req->h+TILE_DY_DIM-1)/TILE_DY_DIM;

   if(pid==0) {
      from=0;
      to=(dycnt<=1)?dycnt:dycnt/2;
   } else {
      if(dycnt <= 1)
         return;
      from=dycnt/2;
      to=dycnt;
   }

   // Load the convolution kernel...
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(0);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(req->ksz);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,0,((NUM_PCORE)-1),0,0,0,(15),0);
   ztaTaskYield();

{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(17,8,0)=((((req->ksz-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(7)*(1);ZTAM_GREG(18,8,0)=48;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=((((req->ksz-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=48;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(1384+(0)*(7)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((req->ksz-1)-(0)+(1))/(1))*(((req->ksz-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(0),t01=(1),t02=(req->ksz*req->ksz-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((67108864)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->kernel)>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1036317|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

   for(ch=0;ch < req->nchannel;ch++) {
      inputLen=req->src_w*req->src_h;
      input=req->input+inputLen*ch;
      inputLen-=y_off*req->src_w;
      input+=y_off*req->src_w;
      input-=req->src_w*pad;
      inputLen+=req->src_w*pad;
      output=req->output+ch*(req->dst_w*req->dst_h);
      for(y=from;y < to;y++) {
         for(x=0;x < dxcnt;x++) {
            cnt=NUM_PCORE;
            // Copy the left-pad from left most tiles edges from memory.
            if(x>0) {

{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(6,8,0)=(4096)*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(22,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=(((((TILE_DY_DIM+2*pad)-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=1119;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(17,8,0)=((((pad-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(18,8,0)=1119;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((VECTOR_WIDTH)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1))*(1);ZTAM_GREG(12,8,0)=1119;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))+(0)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*((((TILE_DY_DIM+2*pad)-1)-(0)+(1))/(1))*(((pad-1)-(0)+(1))/(1))*((((VECTOR_WIDTH)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(UINT8<<5))|((0)<<8);}{int t00=(cnt-1),t01=(1),t02=(cnt-1),t0=(t02-t00);ZTAM_GREG(6,8,0)=(4096)*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(22,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=(((((TILE_DY_DIM+2*pad)-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=1119;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(17,8,0)=((((TILE_DX_DIM+pad-pad-1)-(TILE_DX_DIM-pad)+(1))/(1))-1);ZTAM_GREG(16,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(18,8,0)=1119;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((VECTOR_WIDTH)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1))*(1);ZTAM_GREG(12,8,0)=1119;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))+(TILE_DX_DIM-pad)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
            } else {
               // There is nothing at the left. So set it to zero...
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(6,8,0)=(4096)*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(22,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=(((((TILE_DY_DIM+2*pad)-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=1119;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(17,8,0)=((((pad-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(18,8,0)=1119;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((VECTOR_WIDTH)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1))*(1);ZTAM_GREG(12,8,0)=1119;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))+(0)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*((((TILE_DY_DIM+2*pad)-1)-(0)+(1))/(1))*(((pad-1)-(0)+(1))/(1))*((((VECTOR_WIDTH)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(INT8<<5))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(0);ZTAM_GREG(19,8,0)=(1034269|(INT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
            }

            // Copy input to PCORE array...

{{int t00=(0),t01=(1),t02=((VECTOR_WIDTH-1)),t0=t02,t10=(0),t11=(1),t12=((TILE_DY_DIM+2*pad-1)),t1=t12,t20=(0),t21=(1),t22=((NUM_PCORE-1)),t2=t22,t30=(0),t31=(1),t32=(((pad+TILE_DX_DIM-1)-(pad))),t3=t32;ZTAM_GREG(6,8,0)=(1*((TILE_DY_DIM+2*pad-1)+1)*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=(((VECTOR_WIDTH-1)+1)-t00)*(1*((TILE_DY_DIM+2*pad-1)+1)*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))-1;ZTAM_GREG(22,8,0)=t00*(1*((TILE_DY_DIM+2*pad-1)+1)*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1));ZTAM_GREG(13,8,0)=(1*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=(((TILE_DY_DIM+2*pad-1)+1)-t10)*(1*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))-1;ZTAM_GREG(23,8,0)=t10*(1*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1));ZTAM_GREG(16,8,0)=(1*(((pad+TILE_DX_DIM-1)-(pad))+1))*t21;ZTAM_GREG(17,8,0)=(t2);ZTAM_GREG(18,8,0)=(((NUM_PCORE-1)+1)-t20)*(1*(((pad+TILE_DX_DIM-1)-(pad))+1))-1;ZTAM_GREG(24,8,0)=t20*(1*(((pad+TILE_DX_DIM-1)-(pad))+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((((pad+TILE_DX_DIM-1)-(pad))+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((TILE_DY_DIM+2*pad-1)+1)*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))+t10*(1*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))+t20*(1*(((pad+TILE_DX_DIM-1)-(pad))+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>(((UINT8)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*(t3+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|(UINT8<<5))|((0)<<8);}{int t00=(y*VECTOR_WIDTH),t01=(1),t02=(y*VECTOR_WIDTH+VECTOR_WIDTH-1),t0=(t02-t00),t10=(0),t11=(1),t12=(TILE_DY_DIM+2*pad-1),t1=t12,t20=(x*dx+x_off),t21=(1),t22=(x*dx+dx2+x_off-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(TILE_DY_DIM)*(req->src_w))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((h)-t00)*(1*(TILE_DY_DIM)*(req->src_w))-1;ZTAM_GREG(23,8,0)=t00*(1*(TILE_DY_DIM)*(req->src_w));ZTAM_GREG(16,8,0)=(1*(req->src_w))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=(67108863);ZTAM_GREG(24,8,0)=t10*(1*(req->src_w));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((req->src_w)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(TILE_DY_DIM)*(req->src_w))+t10*(1*(req->src_w))+t20*(1)+0;ZTAM_GREG(31,8,0)=(((inputLen)>>(((UINT8)&1)))-tbar);;ZTAM_GREG(4,8,0)=tbar+((input)>>(((UINT8)&1)));;ZTAM_GREG(19,8,0)=(1036317|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),((DP_CONDITION_SRAM_FLUSH)|0));}{{int t00=(0),t01=(1),t02=(NUM_PCORE-1),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=((((TILE_DY_DIM+2*pad-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=1119;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(5,8,0)=((((pad+TILE_DX_DIM-1)-(pad)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(12,8,0)=1119;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(7,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(6,8,0)=((1))*(1);ZTAM_GREG(11,8,0)=1119;ZTAM_GREG(22,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))+(pad)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((TILE_DY_DIM+2*pad-1)-(0)+(1))/(1))*(((pad+TILE_DX_DIM-1)-(pad)+(1))/(1))*(((VECTOR_WIDTH-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1033247|(UINT8<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((VECTOR_WIDTH-1)),t0=t02,t10=(0),t11=(1),t12=((TILE_DY_DIM+2*pad-1)),t1=t12,t20=(0),t21=(1),t22=((NUM_PCORE-1)),t2=t22,t30=(0),t31=(1),t32=(((pad+TILE_DX_DIM-1)-(pad))),t3=t32;ZTAM_GREG(6,8,0)=(1*((TILE_DY_DIM+2*pad-1)+1)*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=(((VECTOR_WIDTH-1)+1)-t00)*(1*((TILE_DY_DIM+2*pad-1)+1)*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))-1;ZTAM_GREG(22,8,0)=t00*(1*((TILE_DY_DIM+2*pad-1)+1)*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1));ZTAM_GREG(13,8,0)=(1*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=(((TILE_DY_DIM+2*pad-1)+1)-t10)*(1*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))-1;ZTAM_GREG(23,8,0)=t10*(1*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1));ZTAM_GREG(16,8,0)=(1*(((pad+TILE_DX_DIM-1)-(pad))+1))*t21;ZTAM_GREG(17,8,0)=(t2);ZTAM_GREG(18,8,0)=(((NUM_PCORE-1)+1)-t20)*(1*(((pad+TILE_DX_DIM-1)-(pad))+1))-1;ZTAM_GREG(24,8,0)=t20*(1*(((pad+TILE_DX_DIM-1)-(pad))+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((((pad+TILE_DX_DIM-1)-(pad))+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((TILE_DY_DIM+2*pad-1)+1)*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))+t10*(1*((NUM_PCORE-1)+1)*(((pad+TILE_DX_DIM-1)-(pad))+1))+t20*(1*(((pad+TILE_DX_DIM-1)-(pad))+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>(((UINT8)&1)));;ZTAM_GREG(19,8,0)=(1034269|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(DP_CONDITION_SRAM_FLUSH));}

            // Copy the gap from adjacent tile.

            // Copy left margin from right tiles to the immediate left tiles...

{{int t00=(0),t01=(1),t02=(cnt-2),t0=t02;ZTAM_GREG(6,8,0)=(4096)*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(22,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=(((((TILE_DY_DIM+2*pad)-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=1119;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(17,8,0)=((((TILE_DX_DIM+2*pad-1)-(TILE_DX_DIM+pad)+(1))/(1))-1);ZTAM_GREG(16,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(18,8,0)=1119;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((VECTOR_WIDTH)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1))*(1);ZTAM_GREG(12,8,0)=1119;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))+(TILE_DX_DIM+pad)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*((((TILE_DY_DIM+2*pad)-1)-(0)+(1))/(1))*(((TILE_DX_DIM+2*pad-1)-(TILE_DX_DIM+pad)+(1))/(1))*((((VECTOR_WIDTH)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(UINT8<<5))|((0)<<8);}{int t00=(1),t01=(1),t02=(cnt-1),t0=(t02-t00);ZTAM_GREG(6,8,0)=(4096)*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(22,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=(((((TILE_DY_DIM+2*pad)-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=1119;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(17,8,0)=((((2*pad-1)-(pad)+(1))/(1))-1);ZTAM_GREG(16,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(18,8,0)=1119;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((VECTOR_WIDTH)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1))*(1);ZTAM_GREG(12,8,0)=1119;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))+(pad)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(1));}

            // Copy right margin from left tiles to the immediate right tiles...

{{int t00=(1),t01=(1),t02=(cnt-1),t0=(t02-t00);ZTAM_GREG(6,8,0)=(4096)*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(22,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=(((((TILE_DY_DIM+2*pad)-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=1119;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(17,8,0)=((((pad-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(18,8,0)=1119;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((VECTOR_WIDTH)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1))*(1);ZTAM_GREG(12,8,0)=1119;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))+(0)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*((((TILE_DY_DIM+2*pad)-1)-(0)+(1))/(1))*(((pad-1)-(0)+(1))/(1))*((((VECTOR_WIDTH)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(UINT8<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(cnt-2),t0=t02;ZTAM_GREG(6,8,0)=(4096)*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(22,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=(((((TILE_DY_DIM+2*pad)-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=1119;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(17,8,0)=((((TILE_DX_DIM+pad-1)-(TILE_DX_DIM)+(1))/(1))-1);ZTAM_GREG(16,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(18,8,0)=1119;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((VECTOR_WIDTH)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1))*(1);ZTAM_GREG(12,8,0)=1119;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))+(TILE_DX_DIM)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

            if(y==0) {
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(17,8,0)=((((pad-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(18,8,0)=1119;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((TILE_DX_DIM+2*pad)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(12,8,0)=1119;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*((1*(TILE_DX_DIM+2*pad)*(VECTOR_WIDTH)))+(0)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((pad-1)-(0)+(1))/(1))*((((TILE_DX_DIM+2*pad)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((31|(INT8<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(0);ZTAM_GREG(19,8,0)=(1034269|(INT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
            }
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,20,((NUM_PCORE)-1),0,0,0,(15),0);

            ztaTaskYield();

            // Copy result tiles back to memory

{{int t00=(0),t01=(1),t02=((VECTOR_WIDTH-1)),t0=t02,t10=(0),t11=(1),t12=((TILE_DY_DIM-1)),t1=t12,t20=(0),t21=(1),t22=((NUM_PCORE-1)),t2=t22,t30=(0),t31=(1),t32=((TILE_DX_DIM-1)),t3=t32;ZTAM_GREG(6,8,0)=(1*((TILE_DY_DIM-1)+1)*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=(((VECTOR_WIDTH-1)+1)-t00)*(1*((TILE_DY_DIM-1)+1)*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))-1;ZTAM_GREG(22,8,0)=t00*(1*((TILE_DY_DIM-1)+1)*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1));ZTAM_GREG(13,8,0)=(1*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=(((TILE_DY_DIM-1)+1)-t10)*(1*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))-1;ZTAM_GREG(23,8,0)=t10*(1*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1));ZTAM_GREG(16,8,0)=(1*((TILE_DX_DIM-1)+1))*t21;ZTAM_GREG(17,8,0)=(t2);ZTAM_GREG(18,8,0)=(((NUM_PCORE-1)+1)-t20)*(1*((TILE_DX_DIM-1)+1))-1;ZTAM_GREG(24,8,0)=t20*(1*((TILE_DX_DIM-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=(((TILE_DX_DIM-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((TILE_DY_DIM-1)+1)*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))+t10*(1*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))+t20*(1*((TILE_DX_DIM-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>(((UINT8)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*(t3+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|(UINT8<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(NUM_PCORE-1),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=((((TILE_DY_DIM-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(TILE_DX_DIM)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=255;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(5,8,0)=((((TILE_DX_DIM-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(12,8,0)=255;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(7,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(6,8,0)=((1))*(1);ZTAM_GREG(11,8,0)=255;ZTAM_GREG(22,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(1128+(0)*((1*(TILE_DX_DIM)*(VECTOR_WIDTH)))+(0)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1033245|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),((DP_CONDITION_SRAM_FLUSH)|0));}{{int t00=(y*dy),t01=(1),t02=(y*dy+TILE_DY_DIM*VECTOR_WIDTH-1),t0=(t02-t00),t10=(x*dx),t11=(1),t12=(x*dx+dx2-1),t1=(t12-t10);ZTAM_GREG(16,8,0)=(1*(req->dst_w))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((req->dst_h)-t00)*(1*(req->dst_w))-1;ZTAM_GREG(24,8,0)=t00*(1*(req->dst_w));ZTAM_GREG(8,8,0)=((1)*t11);ZTAM_GREG(5,8,0)=(t1);ZTAM_GREG(12,8,0)=((req->dst_w)-1-t10);ZTAM_GREG(25,8,0)=t10*(1);int tbar=t00*(1*(req->dst_w))+t10*(1)+0;ZTAM_GREG(4,8,0)=tbar+((output)>>(((UINT8)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|(UINT8<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((VECTOR_WIDTH-1)),t0=t02,t10=(0),t11=(1),t12=((TILE_DY_DIM-1)),t1=t12,t20=(0),t21=(1),t22=((NUM_PCORE-1)),t2=t22,t30=(0),t31=(1),t32=((TILE_DX_DIM-1)),t3=t32;ZTAM_GREG(6,8,0)=(1*((TILE_DY_DIM-1)+1)*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=(((VECTOR_WIDTH-1)+1)-t00)*(1*((TILE_DY_DIM-1)+1)*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))-1;ZTAM_GREG(22,8,0)=t00*(1*((TILE_DY_DIM-1)+1)*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1));ZTAM_GREG(13,8,0)=(1*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=(((TILE_DY_DIM-1)+1)-t10)*(1*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))-1;ZTAM_GREG(23,8,0)=t10*(1*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1));ZTAM_GREG(16,8,0)=(1*((TILE_DX_DIM-1)+1))*t21;ZTAM_GREG(17,8,0)=(t2);ZTAM_GREG(18,8,0)=(((NUM_PCORE-1)+1)-t20)*(1*((TILE_DX_DIM-1)+1))-1;ZTAM_GREG(24,8,0)=t20*(1*((TILE_DX_DIM-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=(((TILE_DX_DIM-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((TILE_DY_DIM-1)+1)*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))+t10*(1*((NUM_PCORE-1)+1)*((TILE_DX_DIM-1)+1))+t20*(1*((TILE_DX_DIM-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>(((UINT8)&1)));;ZTAM_GREG(19,8,0)=(1034269|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(DP_CONDITION_SRAM_FLUSH));}
         }
      }
   }
}

// Process request from host to do gaussian filtering

void kernel_gaussian_exe(
   unsigned int _req_id,
   unsigned int _input,
   unsigned int _output,
   unsigned int _kernel,
   int _nchannel,
   int _ksz,
   int _w,
   int _h,
   int _src_w,
   int _src_h,
   int _x_off,
   int _y_off,
   int _dst_w,
   int _dst_h
)
{
   Request req;
   
   ztaInitPcore(zta_pcore_img);
   
   req.input=_input;
   req.output=_output;
   req.kernel=_kernel;
   req.nchannel=_nchannel;
   req.ksz=_ksz;
   req.w=_w;
   req.h=_h;
   req.src_w=_src_w;
   req.src_h=_src_h;
   req.x_off=_x_off;
   req.y_off=_y_off;
   req.dst_w=_dst_w;
   req.dst_h=_dst_h;
   
   ztaDualHartExecute(iconv,&req);

   ztaJobDone(_req_id);
}
