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
#include "nn.h"
#include "conv.h"
#include "conv.p.img"

//#define MONITOR

extern void mycallback(int parm2);

typedef struct {
   uint32_t coef;
   uint32_t bias;
   uint32_t biasHi;
   uint32_t biasLo;   
   uint32_t bot;
   uint32_t top;
   uint32_t top_interleave;
   int ksz;
   int topcnt;
   int topdim;
   int botcnt;
   int botdim;
   int group;
   int stride;
   int pad;
   int bias_scale;
   int top_scale;
   int conv_dx;
   int dycnt;
   int groupsz;
   int input_offset;
   int activation_scale;
   int in_interleave;
   int out_interleave;
   uint32_t stream;
} RequestConv;

// Perform 3x3 convolution

static void convolution_3x3(void *_p,int pid) {
   RequestConv *req=(RequestConv *)_p;
   int i,j,k,r,r2,r3,r4,c2,c;
   int ii,jj,kk;
   int offset;
   int index;
   int m,n;
   int x,y;
   int botcnt,botcnt2;
   int topcnt2;
   int topcnt3;
   int botdim;
   int kz,gkz;
   int rowi;
   int from,to;
   int groupsz,group,step;
   int np;
   int stride_dx,stride_dy;
   uint32_t bot,coef;
   int conv_dx,conv_dy,conv_dy2,conv_dx_log,conv_dx2;
   int dysz,dycnt;
   int dx;
   int kfunc;
   int topfmt=UINT8;
   int botfmt=UINT8;
   int biasfmt=INT16;
   int weightfmt=UINT8;
      
   conv_dx=req->conv_dx;
   if(conv_dx <= (NUM_THREAD_PER_CORE/2))
      conv_dx2=NUM_THREAD_PER_CORE/2;
   else
      conv_dx2=NUM_THREAD_PER_CORE;
   conv_dx_log=4;
   conv_dy2=req->groupsz;
   groupsz=req->groupsz;
   dycnt=req->dycnt;
   conv_dy=conv_dy2*dycnt;
   group=NUM_PCORE/groupsz;
   np=group*groupsz;
   step=group<<VECTOR_DEPTH;
   kz=req->ksz*req->ksz;
   gkz=kz*group*VECTOR_WIDTH;
   x=conv_dx*req->stride+req->ksz-req->stride;
   x=ROUND(x,VECTOR_WIDTH);
   y=conv_dy*req->stride+req->ksz-req->stride;
   dysz=x*conv_dy2*req->stride;
   topcnt3=((ROUND(req->topcnt,VECTOR_WIDTH)>>VECTOR_DEPTH)*kz)*VECTOR_WIDTH; 
   topcnt2=req->topcnt/req->group;
   botcnt2=req->botcnt/req->group;
   botdim=req->botdim-2*req->pad;
   stride_dy=conv_dy*req->stride;
   stride_dx=conv_dx*req->stride;
   botcnt=req->botcnt;
   bot=req->bot;
   coef=req->coef;

   kfunc=675;
   if(x > CONV_SMALL_BOT_DX) ztaAbort(0);
   if(y > CONV_SMALL_BOT_DY) ztaAbort(0);
   if(req->group > 2) ztaAbort(0);

{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(24);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(req->stride);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(27);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(req->activation_scale);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(28);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(req->bias_scale);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(25);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(conv_dx_log);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(29);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(x);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
   for(i=0;i < np;i++) {
      index=(i%groupsz);
{{int t00=(i),t01=(1),t02=(i),t0=(t02-t00),t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(26);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(index);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
   }
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,20,((np)-1),0,0,0,(15),0);
   ztaTaskYield();
   if(pid==0) {
      from=0;
      to=ROUND(req->topcnt/2,step);
   } else {
      from=ROUND(req->topcnt/2,step);
      to=req->topcnt;
   }
{int t00=(0),t01=(1),t02=((group)-1),t0=t02,t10=(0),t11=(1),t12=(0),t1=t12;ZTAM_GREG(6,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(22,8,0)=t00*(4096*(groupsz));ZTAM_GREG(13,8,0)=(4096)*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(23,8,0)=t10*(4096);ZTAM_GREG(17,8,0)=((((kz-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(8)*(1);ZTAM_GREG(18,8,0)=391;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=391;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(8+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*(((kz-1)-(0)+(1))/(1))*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((1|((weightfmt)<<5))|((((((groupsz)-1))&((1<<(MCAST_WIDTH-1))-1))+(0<<(MCAST_WIDTH-1)))<<14))|((0)<<8)|((0)<<1);}
{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((x*y-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=959;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(416+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((x*y-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((1|((botfmt)<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8)|((1)<<1);}
   for(i=from;i < to;i += step) {
{{int t00=(0),t01=(1),t02=((group)-1),t0=t02,t10=(0),t11=(1),t12=(0),t1=t12;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(400+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((31|((biasfmt)<<5))|((((((groupsz)-1))&((1<<(MCAST_WIDTH-1))-1))+(0<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+step-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->biasHi)>>((((biasfmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((biasfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=((group)-1),t0=t02,t10=(0),t11=(1),t12=(0),t1=t12;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(408+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((31|((biasfmt)<<5))|((((((groupsz)-1))&((1<<(MCAST_WIDTH-1))-1))+(0<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+step-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->biasLo)>>((((biasfmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((biasfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
      rowi=((i>>VECTOR_DEPTH)*kz)*VECTOR_WIDTH;
      ii=(i/topcnt2)*botcnt2;
{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(rowi),t11=(1),t12=(rowi+gkz-1),t1=(t12-t10);ZTAM_GREG(16,8,0)=(1*(topcnt3))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((botcnt2)-t00)*(1*(topcnt3))-1;ZTAM_GREG(24,8,0)=t00*(1*(topcnt3));ZTAM_GREG(8,8,0)=((1)*t11);ZTAM_GREG(5,8,0)=(t1);ZTAM_GREG(12,8,0)=((topcnt3)-1-t10);ZTAM_GREG(25,8,0)=t10*(1);int tbar=t00*(1*(topcnt3))+t10*(1)+0;ZTAM_GREG(4,8,0)=tbar+((coef)>>((((weightfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036289|((weightfmt)<<5))|((0)<<8)|((2)<<1);}
      for(r=0,r2=-req->pad;r < req->topdim;r += conv_dy,r2 += stride_dy) {
         for(c=0,c2=-req->pad;c < req->topdim;c += conv_dx,c2+=stride_dx) {
{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(r2),t11=(1),t12=(r2+y-1),t1=(t12-t10),t20=(c2),t21=(1),t22=(c2+x-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(botdim)*(botdim))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((botcnt)-t00)*(1*(botdim)*(botdim))-1;ZTAM_GREG(23,8,0)=t00*(1*(botdim)*(botdim));ZTAM_GREG(16,8,0)=(1*(botdim))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((botdim)-t10)*(1*(botdim))-1;ZTAM_GREG(24,8,0)=t10*(1*(botdim));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((botdim)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(botdim)*(botdim))+t10*(1*(botdim))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((bot)>>((((botfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*((0)+1));ZTAM_GREG(28,8,0)=(-req->input_offset);ZTAM_GREG(19,8,0)=(1036289|((botfmt)<<5))|((0)<<8)|((3)<<1);}
ZTAM_GREG(0,23,0)=(dycnt);
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,0,((np)-1),0,1,0,(15),0);
            for(jj=0;jj < botcnt2;jj++) {
               ztaTaskYield(); 
               j=jj+ii;
{{ZTAM_GREG(1,13,0)=0;ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_DEST<<1);}{ZTAM_GREG(3,13,0)=0;{int t00=(j),t01=(1),t02=(j),t0=(t02-t00),t10=(r2),t11=(1),t12=(r2+y-1),t1=(t12-t10),t20=(c2),t21=(1),t22=(c2+x-1),t2=(t22-t20);int tbar=t00*(1*(botdim)*(botdim))+0;ZTAM_GREG(4,8,0)=tbar+0;;ZTAM_GREG(28,8,0)=(-req->input_offset);}ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_SRC<<1);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((1)>=0)?1:0,(1)&(3),(0));}
{{ZTAM_GREG(0,13,0)=0;ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_DEST<<1);}{ZTAM_GREG(2,13,0)=0;{int t00=(jj),t01=(1),t02=(jj),t0=(t02-t00),t10=(rowi),t11=(1),t12=(rowi+gkz-1),t1=(t12-t10);int tbar=t00*(1*(topcnt3))+0;ZTAM_GREG(4,8,0)=tbar+0;;}ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_SRC<<1);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((2)>=0)?1:0,(2)&(3),(0));}
               dx=req->topdim-c;
               if(dx > conv_dx)
                  dx=conv_dx;
               for(kk=0,offset=0,r4=r;kk < dycnt;kk++,offset+=dysz,r4+=conv_dy2) {
                  if(r4 >= req->topdim)
                     break;
ZTAM_GREG(0,23,0)=(kk);
ZTAM_GREG(0,24,0)=(offset);
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,EXE_FUNC_FIELD((kfunc)),((np)-1),0,EXE_P0_FIELD((kfunc)),EXE_P1_FIELD((kfunc)),((dx)-1),EXE_MODEL_FIELD((kfunc)));
               }
            } 
            for(jj=0;jj < dycnt;jj++) {
ZTAM_GREG(0,23,0)=(jj);
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,60,((np)-1),0,1,0,(15),0);
            }
            ztaTaskYield();
            if(req->out_interleave==kTensorFormatInterleaved || req->out_interleave==kTensorFormatFlatAndInterleaved) {
               if(conv_dx2==NUM_THREAD_PER_CORE) {
{{int t00=(r),t01=(1),t02=(r+conv_dy-1),t0=(t02-t00),t10=(c),t11=(1),t12=(c+conv_dx2-1),t1=(t12-t10),t20=(i),t21=(1),t22=(i+step-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(req->topdim)*(req->topcnt))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((req->topdim)-t00)*(1*(req->topdim)*(req->topcnt))-1;ZTAM_GREG(23,8,0)=t00*(1*(req->topdim)*(req->topcnt));ZTAM_GREG(16,8,0)=(1*(req->topcnt))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((req->topdim)-t10)*(1*(req->topcnt))-1;ZTAM_GREG(24,8,0)=t10*(1*(req->topcnt));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(req->topdim)*(req->topcnt))+t10*(1*(req->topcnt))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->top_interleave)>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(group-1),t0=t02,t10=(0),t11=(1),t12=(groupsz-1),t1=t12,t20=(0),t21=(1),t22=(NUM_THREAD_PER_CORE-1),t2=t22;ZTAM_GREG(16,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(24,8,0)=t00*(4096*(groupsz));ZTAM_GREG(6,8,0)=(4096)*t11;ZTAM_GREG(7,8,0)=(t1);ZTAM_GREG(11,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(22,8,0)=t10*(4096);ZTAM_GREG(13,8,0)=(256)*t21;ZTAM_GREG(14,8,0)=(t2);ZTAM_GREG(15,8,0)=((256)-t20)*(256)-1;ZTAM_GREG(23,8,0)=t20*(256);ZTAM_GREG(3,8,0)=((((dycnt-1)-(0)+(1))/(1))-1);ZTAM_GREG(2,8,0)=(8)*(1);ZTAM_GREG(10,8,0)=15;ZTAM_GREG(21,8,0)=0;ZTAM_GREG(5,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=15;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t20*(256)+t10*(4096)+t00*(4096*(groupsz))+(0+(0)*(8)+(0));ZTAM_GREG(19,8,0)=(1032221|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),(0));}
               } else {
{{int t00=(r),t01=(1),t02=(r+conv_dy-1),t0=(t02-t00),t10=(c),t11=(1),t12=(c+conv_dx2-1),t1=(t12-t10),t20=(i),t21=(1),t22=(i+step-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(req->topdim)*(req->topcnt))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((req->topdim)-t00)*(1*(req->topdim)*(req->topcnt))-1;ZTAM_GREG(23,8,0)=t00*(1*(req->topdim)*(req->topcnt));ZTAM_GREG(16,8,0)=(1*(req->topcnt))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((req->topdim)-t10)*(1*(req->topcnt))-1;ZTAM_GREG(24,8,0)=t10*(1*(req->topcnt));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(req->topdim)*(req->topcnt))+t10*(1*(req->topcnt))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->top_interleave)>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(group-1),t0=t02,t10=(0),t11=(1),t12=(groupsz-1),t1=t12,t20=(0),t21=(1),t22=(NUM_THREAD_PER_CORE/2-1),t2=t22;ZTAM_GREG(16,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(24,8,0)=t00*(4096*(groupsz));ZTAM_GREG(6,8,0)=(4096)*t11;ZTAM_GREG(7,8,0)=(t1);ZTAM_GREG(11,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(22,8,0)=t10*(4096);ZTAM_GREG(13,8,0)=(256)*t21;ZTAM_GREG(14,8,0)=(t2);ZTAM_GREG(15,8,0)=((256)-t20)*(256)-1;ZTAM_GREG(23,8,0)=t20*(256);ZTAM_GREG(3,8,0)=((((dycnt-1)-(0)+(1))/(1))-1);ZTAM_GREG(2,8,0)=(8)*(1);ZTAM_GREG(10,8,0)=15;ZTAM_GREG(21,8,0)=0;ZTAM_GREG(5,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=15;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t20*(256)+t10*(4096)+t00*(4096*(groupsz))+(0+(0)*(8)+(0));ZTAM_GREG(19,8,0)=(1032221|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),(0));}
               }
            }
            if(req->out_interleave==kTensorFormatFlat || req->out_interleave==kTensorFormatFlatAndInterleaved) {
               if(conv_dx2==NUM_THREAD_PER_CORE) {
{{int t00=(0),t01=(1),t02=((group-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((dycnt-1)),t2=t22,t30=(0),t31=(1),t32=(((groupsz)-1)),t3=t32,t40=(0),t41=(1),t42=((2-1)),t4=t42,t50=(0),t51=(1),t52=((8-1)),t5=t52;ZTAM_GREG(13,8,0)=(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=(((group-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))-1;ZTAM_GREG(23,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1));ZTAM_GREG(0,8,0)=(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))*t11;ZTAM_GREG(1,8,0)=(t1);ZTAM_GREG(9,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))-1;ZTAM_GREG(20,8,0)=t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1));ZTAM_GREG(2,8,0)=(1*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))*t21;ZTAM_GREG(3,8,0)=(t2);ZTAM_GREG(10,8,0)=(((dycnt-1)+1)-t20)*(1*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))-1;ZTAM_GREG(21,8,0)=t20*(1*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1));ZTAM_GREG(16,8,0)=(1*((2-1)+1)*((8-1)+1))*t31;ZTAM_GREG(17,8,0)=(t3);ZTAM_GREG(18,8,0)=((((groupsz)-1)+1)-t30)*(1*((2-1)+1)*((8-1)+1))-1;ZTAM_GREG(24,8,0)=t30*(1*((2-1)+1)*((8-1)+1));ZTAM_GREG(6,8,0)=(1*((8-1)+1))*t41;ZTAM_GREG(7,8,0)=(t4);ZTAM_GREG(11,8,0)=(((2-1)+1)-t40)*(1*((8-1)+1))-1;ZTAM_GREG(22,8,0)=t40*(1*((8-1)+1));ZTAM_GREG(8,8,0)=((1)*t51);ZTAM_GREG(5,8,0)=(t5);ZTAM_GREG(12,8,0)=(((8-1)+1)-1-t50);ZTAM_GREG(25,8,0)=t50*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))+t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))+t20*(1*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))+t30*(1*((2-1)+1)*((8-1)+1))+t40*(1*((8-1)+1))+t50*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*(t3+1)*(t4+1)*(t5+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(group-1),t0=t02,t10=(0),t11=(1),t12=((groupsz)-1),t1=t12,t20=(0),t21=(1),t22=(2-1),t2=t22,t30=(0),t31=(1),t32=(8-1),t3=t32;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(6,8,0)=(256*8)*t21;ZTAM_GREG(7,8,0)=(t2);ZTAM_GREG(11,8,0)=((256*8)-t20)*(256*8)-1;ZTAM_GREG(22,8,0)=t20*(256*8);ZTAM_GREG(8,8,0)=(256)*t31;ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((256)-t30)*(256)-1;ZTAM_GREG(25,8,0)=t30*(256);ZTAM_GREG(3,8,0)=((((dycnt-1)-(0)+(1))/(1))-1);ZTAM_GREG(2,8,0)=(8)*(1);ZTAM_GREG(10,8,0)=15;ZTAM_GREG(21,8,0)=0;ZTAM_GREG(1,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(0,8,0)=(1)*(1);ZTAM_GREG(9,8,0)=15;ZTAM_GREG(20,8,0)=0;ZTAM_GREG(4,8,0)=t30*(256)+t20*(256*8)+t10*(4096)+t00*(4096*(groupsz))+(0+(0)*(8)+(0));ZTAM_GREG(19,8,0)=(1033245|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),((DP_CONDITION_SRAM_FLUSH)|0));}{{int t00=(i),t01=(1),t02=(i+step-1),t0=(t02-t00),t10=(r),t11=(1),t12=(r+conv_dy-1),t1=(t12-t10),t20=(c),t21=(1),t22=(c+conv_dx2-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(req->topdim)*(req->topdim))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((req->topcnt)-t00)*(1*(req->topdim)*(req->topdim))-1;ZTAM_GREG(23,8,0)=t00*(1*(req->topdim)*(req->topdim));ZTAM_GREG(16,8,0)=(1*(req->topdim))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((req->topdim)-t10)*(1*(req->topdim))-1;ZTAM_GREG(24,8,0)=t10*(1*(req->topdim));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((req->topdim)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(req->topdim)*(req->topdim))+t10*(1*(req->topdim))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->top)>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((group-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((dycnt-1)),t2=t22,t30=(0),t31=(1),t32=(((groupsz)-1)),t3=t32,t40=(0),t41=(1),t42=((2-1)),t4=t42,t50=(0),t51=(1),t52=((8-1)),t5=t52;ZTAM_GREG(0,8,0)=(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))*t01;ZTAM_GREG(1,8,0)=(t0);ZTAM_GREG(9,8,0)=(((group-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))-1;ZTAM_GREG(20,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1));ZTAM_GREG(2,8,0)=(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))*t11;ZTAM_GREG(3,8,0)=(t1);ZTAM_GREG(10,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))-1;ZTAM_GREG(21,8,0)=t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1));ZTAM_GREG(6,8,0)=(1*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))*t21;ZTAM_GREG(7,8,0)=(t2);ZTAM_GREG(11,8,0)=(((dycnt-1)+1)-t20)*(1*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))-1;ZTAM_GREG(22,8,0)=t20*(1*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1));ZTAM_GREG(13,8,0)=(1*((2-1)+1)*((8-1)+1))*t31;ZTAM_GREG(14,8,0)=(t3);ZTAM_GREG(15,8,0)=((((groupsz)-1)+1)-t30)*(1*((2-1)+1)*((8-1)+1))-1;ZTAM_GREG(23,8,0)=t30*(1*((2-1)+1)*((8-1)+1));ZTAM_GREG(16,8,0)=(1*((8-1)+1))*t41;ZTAM_GREG(17,8,0)=(t4);ZTAM_GREG(18,8,0)=(((2-1)+1)-t40)*(1*((8-1)+1))-1;ZTAM_GREG(24,8,0)=t40*(1*((8-1)+1));ZTAM_GREG(8,8,0)=((1)*t51);ZTAM_GREG(5,8,0)=(t5);ZTAM_GREG(12,8,0)=(((8-1)+1)-1-t50);ZTAM_GREG(25,8,0)=t50*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))+t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))+t20*(1*(((groupsz)-1)+1)*((2-1)+1)*((8-1)+1))+t30*(1*((2-1)+1)*((8-1)+1))+t40*(1*((8-1)+1))+t50*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((topfmt))&1)));;ZTAM_GREG(19,8,0)=(1034269|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(DP_CONDITION_SRAM_FLUSH));}
               } else {
{{int t00=(0),t01=(1),t02=((group-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((dycnt-1)),t2=t22,t30=(0),t31=(1),t32=(((groupsz)-1)),t3=t32,t40=(0),t41=(1),t42=((NUM_THREAD_PER_CORE/2-1)),t4=t42;ZTAM_GREG(13,8,0)=(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=(((group-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))-1;ZTAM_GREG(23,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1));ZTAM_GREG(2,8,0)=(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))*t11;ZTAM_GREG(3,8,0)=(t1);ZTAM_GREG(10,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))-1;ZTAM_GREG(21,8,0)=t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1));ZTAM_GREG(6,8,0)=(1*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))*t21;ZTAM_GREG(7,8,0)=(t2);ZTAM_GREG(11,8,0)=(((dycnt-1)+1)-t20)*(1*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))-1;ZTAM_GREG(22,8,0)=t20*(1*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1));ZTAM_GREG(16,8,0)=(1*((NUM_THREAD_PER_CORE/2-1)+1))*t31;ZTAM_GREG(17,8,0)=(t3);ZTAM_GREG(18,8,0)=((((groupsz)-1)+1)-t30)*(1*((NUM_THREAD_PER_CORE/2-1)+1))-1;ZTAM_GREG(24,8,0)=t30*(1*((NUM_THREAD_PER_CORE/2-1)+1));ZTAM_GREG(8,8,0)=((1)*t41);ZTAM_GREG(5,8,0)=(t4);ZTAM_GREG(12,8,0)=(((NUM_THREAD_PER_CORE/2-1)+1)-1-t40);ZTAM_GREG(25,8,0)=t40*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))+t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))+t20*(1*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))+t30*(1*((NUM_THREAD_PER_CORE/2-1)+1))+t40*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*(t3+1)*(t4+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(group-1),t0=t02,t10=(0),t11=(1),t12=((groupsz)-1),t1=t12,t20=(0),t21=(1),t22=(NUM_THREAD_PER_CORE/2-1),t2=t22;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(8,8,0)=(256)*t21;ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((256)-t20)*(256)-1;ZTAM_GREG(25,8,0)=t20*(256);ZTAM_GREG(7,8,0)=((((dycnt-1)-(0)+(1))/(1))-1);ZTAM_GREG(6,8,0)=(8)*(1);ZTAM_GREG(11,8,0)=15;ZTAM_GREG(22,8,0)=0;ZTAM_GREG(3,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(2,8,0)=(1)*(1);ZTAM_GREG(10,8,0)=15;ZTAM_GREG(21,8,0)=0;ZTAM_GREG(4,8,0)=t20*(256)+t10*(4096)+t00*(4096*(groupsz))+(0+(0)*(8)+(0));ZTAM_GREG(19,8,0)=(1033245|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),((DP_CONDITION_SRAM_FLUSH)|0));}{{int t00=(i),t01=(1),t02=(i+step-1),t0=(t02-t00),t10=(r),t11=(1),t12=(r+conv_dy-1),t1=(t12-t10),t20=(c),t21=(1),t22=(c+conv_dx2-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(req->topdim)*(req->topdim))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((req->topcnt)-t00)*(1*(req->topdim)*(req->topdim))-1;ZTAM_GREG(23,8,0)=t00*(1*(req->topdim)*(req->topdim));ZTAM_GREG(16,8,0)=(1*(req->topdim))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((req->topdim)-t10)*(1*(req->topdim))-1;ZTAM_GREG(24,8,0)=t10*(1*(req->topdim));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((req->topdim)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(req->topdim)*(req->topdim))+t10*(1*(req->topdim))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->top)>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((group-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((dycnt-1)),t2=t22,t30=(0),t31=(1),t32=(((groupsz)-1)),t3=t32,t40=(0),t41=(1),t42=((NUM_THREAD_PER_CORE/2-1)),t4=t42;ZTAM_GREG(2,8,0)=(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))*t01;ZTAM_GREG(3,8,0)=(t0);ZTAM_GREG(10,8,0)=(((group-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))-1;ZTAM_GREG(21,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1));ZTAM_GREG(6,8,0)=(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))*t11;ZTAM_GREG(7,8,0)=(t1);ZTAM_GREG(11,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))-1;ZTAM_GREG(22,8,0)=t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1));ZTAM_GREG(13,8,0)=(1*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))*t21;ZTAM_GREG(14,8,0)=(t2);ZTAM_GREG(15,8,0)=(((dycnt-1)+1)-t20)*(1*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))-1;ZTAM_GREG(23,8,0)=t20*(1*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1));ZTAM_GREG(16,8,0)=(1*((NUM_THREAD_PER_CORE/2-1)+1))*t31;ZTAM_GREG(17,8,0)=(t3);ZTAM_GREG(18,8,0)=((((groupsz)-1)+1)-t30)*(1*((NUM_THREAD_PER_CORE/2-1)+1))-1;ZTAM_GREG(24,8,0)=t30*(1*((NUM_THREAD_PER_CORE/2-1)+1));ZTAM_GREG(8,8,0)=((1)*t41);ZTAM_GREG(5,8,0)=(t4);ZTAM_GREG(12,8,0)=(((NUM_THREAD_PER_CORE/2-1)+1)-1-t40);ZTAM_GREG(25,8,0)=t40*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))+t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))+t20*(1*(((groupsz)-1)+1)*((NUM_THREAD_PER_CORE/2-1)+1))+t30*(1*((NUM_THREAD_PER_CORE/2-1)+1))+t40*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((topfmt))&1)));;ZTAM_GREG(19,8,0)=(1034269|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(DP_CONDITION_SRAM_FLUSH));}
               }
            }
         }
      }
   }
}

#define MIN_DYCNT  5 // Minimum dycnt required to avoid MCORE instruction FIFO underrun.

// Doing 1x1 convolution

static void convolution_1x1(void *_p,int pid) {
   RequestConv *req=(RequestConv *)_p;
   int i,k,r,r2,r3,c2,c;
   int ii,jj;
   register int kk;
   int topoffset;
   int index;
   int m,n;
   int xy;
   int botcnt,botcnt2;
   int topcnt,topcnt2;
   int topcnt3;
   int kz,gkz;
   int mm;
   int rowi;
   int from,to;
   int groupsz,group,step;
   int np,topsz,botsz;
   uint32_t top2,bot,top2bot,coef;
   int conv_dx;
   int dysz,dycnt,dycntLast,dzcnt,dycnt2,xy2,xy3,xy4;
   int remain,delta;
   int topfmt=UINT8;
   int botfmt=UINT8;
   int biasfmt=INT16;	
   int weightfmt=UINT8;
   uint32_t f,f_activate;
   int mindycnt,batchcnt;
   int cnt;
   static uint32_t kfunc[8]={4227,4163,4067,3939,
                             3779,3587,3363,3107};

   topsz=req->topdim*req->topdim;
   botsz=req->botdim*req->botdim;
   np=NUM_PCORE;
   kz=req->ksz*req->ksz;
   topcnt=0;
   topoffset=0;
   for(group=NUM_PCORE,groupsz=1;group >= 1;group=(group>>1),groupsz=(groupsz<<1)) {
      
      // pcores are divided into group where each group work on the 
      // same convolution tensor.
      // We want to start with the smallest group so that we can process
      // as many tensors at the same time as we can
      // And the remaining tensors after each pass will be processed in a larger group
      // This ensures maximum usage of computation resources with the least
      // waste...

      topoffset+=topcnt; 
      topcnt=req->topcnt-topoffset;
      if(topcnt<=0)
         break;
      topcnt2=ROUND((topcnt+1)/2,VECTOR_WIDTH);
      batchcnt=group*VECTOR_WIDTH;
      if(group > 1)
         topcnt2=(topcnt2/batchcnt)*batchcnt; // Round down
      else
         topcnt2=((topcnt2+batchcnt-1)/batchcnt)*batchcnt; // Round up
      topcnt2=topcnt2*2;
      if(topcnt2 < topcnt)
         topcnt=topcnt2;
      if(topcnt==0)
         continue;

      // First round, do everything in groupsz=1
      if(groupsz==1) {
         for(i=NUM_MIN_THREAD_FOR_MAX_EFFICIENCY;i <= NUM_THREAD_PER_CORE;i++) {
            dycnt=(topsz+(i*groupsz)-1)/(i*groupsz);
            if((dycnt < mindycnt)||(i==NUM_MIN_THREAD_FOR_MAX_EFFICIENCY)) {
               mindycnt=dycnt;
               conv_dx=i;
            }
         }
      } else {
         // When groupsz>1; conv_dx has to be NUM_THREAD inorder to be able to do TX efficiently
         conv_dx=NUM_THREAD_PER_CORE;
      }
      step=group<<VECTOR_DEPTH;
      gkz=kz*group*VECTOR_WIDTH;
      dysz=conv_dx*groupsz;
      dycnt=(topsz+dysz-1)/dysz;
      if(dycnt > CONV_1X1_Y_DIM)
         dycnt=CONV_1X1_Y_DIM;
      while(ROUND(dycnt*dysz,VECTOR_WIDTH) > CONV_1X1_BOTSZ)
         dycnt--;
      dycntLast=((topsz%(dycnt*dysz))+dysz-1)/dysz;
      xy=dysz*dycnt;

      topcnt3=((ROUND(req->topcnt,VECTOR_WIDTH)>>VECTOR_DEPTH)*kz)*VECTOR_WIDTH; 
      botcnt2=req->botcnt/req->group;
      botcnt=req->botcnt;
      bot=req->bot;
      coef=req->coef;

      // Check if we can do 2 top element at a time.
      if((xy>=topsz) && (botcnt2&1)==0 && (dycnt <= (CONV_1X1_Y_DIM/2)) && ROUND(xy*2,VECTOR_WIDTH) <= CONV_1X1_BOTSZ) {
         // Can do 2 at a time of a top element fit within one interation and there is enough memory
         // to hold 2. And number of botcnt is even
         dzcnt=2;
      } else {
         dzcnt=1;
      }
      if(req->group > 2) ztaAbort(0);

      // Initialize convolution module...

{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(1);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(req->activation_scale);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(2);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(dysz);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(3);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(conv_dx);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
      for(i=0;i < np;i++) {
         if(req->ksz==11)
            index=0;
         else
            index=(i%groupsz);
{{int t00=(i),t01=(1),t02=(i),t0=(t02-t00),t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(0);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(index);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
      }
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,176,((np)-1),0,0,0,(15),0);
      ztaTaskYield();
      if(pid==0) {
         from=0;
         to=ROUND((topcnt+1)/2,VECTOR_WIDTH);
      } else {
         from=ROUND((topcnt+1)/2,VECTOR_WIDTH);
         to=topcnt;
      }
      from+=topoffset;
      to+=topoffset;

      f_activate=ztaBuildKernelFunc(4259,np,conv_dx);

{int t00=(0),t01=(1),t02=((group)-1),t0=t02,t10=(0),t11=(1),t12=(0),t1=t12;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(7,8,0)=((((dzcnt-1)-(0)+(1))/(1))-1);ZTAM_GREG(6,8,0)=(8)*(1);ZTAM_GREG(11,8,0)=31;ZTAM_GREG(22,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=31;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(8+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*(((dzcnt-1)-(0)+(1))/(1))*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((1|((weightfmt)<<5))|((((((groupsz)-1))&((1<<(MCAST_WIDTH-1))-1))+(0<<(MCAST_WIDTH-1)))<<14))|((0)<<8)|((0)<<1);}

      for(i=from;i < to;i += step)
      {
{{int t00=(0),t01=(1),t02=((group)-1),t0=t02,t10=(0),t11=(1),t12=(0),t1=t12;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(40+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((31|((biasfmt)<<5))|((((((groupsz)-1))&((1<<(MCAST_WIDTH-1))-1))+(0<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+step-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->biasHi)>>((((biasfmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((biasfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=((group)-1),t0=t02,t10=(0),t11=(1),t12=(0),t1=t12;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(48+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((31|((biasfmt)<<5))|((((((groupsz)-1))&((1<<(MCAST_WIDTH-1))-1))+(0<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+step-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->biasLo)>>((((biasfmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((biasfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

         rowi=((i>>VECTOR_DEPTH)*kz)*VECTOR_WIDTH;
{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(((dzcnt)-1)),t1=t12,t20=(rowi),t21=(1),t22=(rowi+gkz-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(dzcnt)*(topcnt3))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((botcnt2/dzcnt)-t00)*(1*(dzcnt)*(topcnt3))-1;ZTAM_GREG(23,8,0)=t00*(1*(dzcnt)*(topcnt3));ZTAM_GREG(16,8,0)=(1*(topcnt3))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((dzcnt)-t10)*(1*(topcnt3))-1;ZTAM_GREG(24,8,0)=t10*(1*(topcnt3));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((topcnt3)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(dzcnt)*(topcnt3))+t10*(1*(topcnt3))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((coef)>>((((weightfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036289|((weightfmt)<<5))|((0)<<8)|((1)<<1);}
         for(mm=0;mm < topsz;) {
            dycnt2=(topsz-mm+dysz-1)/dysz;
            if(dycnt2 > dycnt)
               dycnt2=dycnt;
            if(dycnt2 > MIN_DYCNT && dycntLast < MIN_DYCNT) {
               // dycnt needs at least to be MIN_DYCNT to avoid not feeding instruction to mcore fast enough
               // The last loop may not have enough dycnt, so offload some dycnt from previous loop to the last 
               // loop.
               // Its important to make sure mcore instruction fifo is always fed with enough instructions
               int extra;
               extra=(dycnt2-MIN_DYCNT);
               if(extra > (MIN_DYCNT-dycntLast))
                  extra=(MIN_DYCNT-dycntLast);
               dycnt2-=extra;
               dycntLast+=extra;
            }
            f=ztaBuildKernelFunc(kfunc[dycnt2-1],NUM_PCORE,conv_dx);
            xy2=conv_dx*groupsz*dycnt2;
            xy3=ROUND(xy2,VECTOR_WIDTH);
            xy4=xy3*dzcnt;
            if(dzcnt>1 && xy4 > (dzcnt*botsz))
               xy4=ROUND(dzcnt*botsz,VECTOR_WIDTH);      
{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(mm),t11=(1),t12=(mm+xy4-1),t1=(t12-t10);ZTAM_GREG(16,8,0)=(1*(botsz*dzcnt))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((botcnt/dzcnt)-t00)*(1*(botsz*dzcnt))-1;ZTAM_GREG(24,8,0)=t00*(1*(botsz*dzcnt));ZTAM_GREG(8,8,0)=((1)*t11);ZTAM_GREG(5,8,0)=(t1);ZTAM_GREG(12,8,0)=((botsz*dzcnt)-1-t10);ZTAM_GREG(25,8,0)=t10*(1);int tbar=t00*(1*(botsz*dzcnt))+t10*(1)+0;ZTAM_GREG(4,8,0)=tbar+((bot)>>((((botfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036289|((botfmt)<<5))|((0)<<8)|((2)<<1);}
{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((xy4-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=839;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(1080+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((xy4-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((1|((botfmt)<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8)|((3)<<1);}
ZTAM_GREG(0,23,0)=(dycnt2);
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,156,((np)-1),0,1,0,(15),0);

            // Do convolution...
            
            if(dzcnt > 1) {
               cnt=botcnt2/dzcnt;
               for(jj=0;jj < cnt;jj++) {
                  ztaTaskYield(); 
{{ZTAM_GREG(3,13,0)=0;ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_DEST<<1);}{ZTAM_GREG(2,13,0)=0;{int t00=(jj),t01=(1),t02=(jj),t0=(t02-t00),t10=(mm),t11=(1),t12=(mm+xy4-1),t1=(t12-t10);int tbar=t00*(1*(botsz*dzcnt))+0;ZTAM_GREG(4,8,0)=tbar+0;;}ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_SRC<<1);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((1)>=0)?1:0,(1)&(3),(0));}
{{ZTAM_GREG(0,13,0)=0;ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_DEST<<1);}{ZTAM_GREG(1,13,0)=0;{int t00=(jj),t01=(1),t02=(jj),t0=(t02-t00),t10=(0),t11=(1),t12=(((dzcnt)-1)),t1=t12,t20=(rowi),t21=(1),t22=(rowi+gkz-1),t2=(t22-t20);int tbar=t00*(1*(dzcnt)*(topcnt3))+0;ZTAM_GREG(4,8,0)=tbar+0;;}ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_SRC<<1);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((2)>=0)?1:0,(2)&(3),(0));}
ZTAM_GREG(0,23,0)=(0);
ZTAM_GREG(0,24,0)=(0);
;ZTAM_GREG(0,5,0)=(f);
ZTAM_GREG(0,23,0)=(botsz);
ZTAM_GREG(0,24,0)=(1);
;ZTAM_GREG(0,5,0)=(f);
               }
            } else {
ZTAM_GREG(0,23,0)=(0);
ZTAM_GREG(0,24,0)=(0);
               for(jj=0;jj < botcnt2;jj+=dzcnt) {
                  ztaTaskYield(); 
{{ZTAM_GREG(3,13,0)=0;ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_DEST<<1);}{ZTAM_GREG(2,13,0)=0;{int t00=(jj),t01=(1),t02=(jj),t0=(t02-t00),t10=(mm),t11=(1),t12=(mm+xy4-1),t1=(t12-t10);int tbar=t00*(1*(botsz*dzcnt))+0;ZTAM_GREG(4,8,0)=tbar+0;;}ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_SRC<<1);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((1)>=0)?1:0,(1)&(3),(0));}
{{ZTAM_GREG(0,13,0)=0;ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_DEST<<1);}{ZTAM_GREG(1,13,0)=0;{int t00=(jj),t01=(1),t02=(jj),t0=(t02-t00),t10=(0),t11=(1),t12=(((dzcnt)-1)),t1=t12,t20=(rowi),t21=(1),t22=(rowi+gkz-1),t2=(t22-t20);int tbar=t00*(1*(dzcnt)*(topcnt3))+0;ZTAM_GREG(4,8,0)=tbar+0;;}ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_SRC<<1);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((2)>=0)?1:0,(2)&(3),(0));}
;ZTAM_GREG(0,5,0)=(f);
               }
            }
            ztaTaskYield();	
            
            // Do activation step... 
            
            for(jj=0;jj < dycnt2;jj++)
            { 
ZTAM_GREG(0,23,0)=(jj);
ZTAM_GREG(0,24,0)=(jj*conv_dx);
;ZTAM_GREG(0,5,0)=(f_activate);
            }
            ztaTaskYield();
            
            // Output results...
            
            if(groupsz > 1) {
               if(req->out_interleave==kTensorFormatInterleaved || req->out_interleave==kTensorFormatFlatAndInterleaved) {
                  // Output in interleave format
{{int t00=(mm),t01=(1),t02=(mm+xy2-1),t0=(t02-t00),t10=(i),t11=(1),t12=(i+step-1),t1=(t12-t10);ZTAM_GREG(16,8,0)=(1*(req->topcnt))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((topsz)-t00)*(1*(req->topcnt))-1;ZTAM_GREG(24,8,0)=t00*(1*(req->topcnt));ZTAM_GREG(8,8,0)=((1)*t11);ZTAM_GREG(5,8,0)=(t1);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t10);ZTAM_GREG(25,8,0)=t10*(1);int tbar=t00*(1*(req->topcnt))+t10*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->top_interleave)>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(group-1),t0=t02,t10=(0),t11=(1),t12=(groupsz-1),t1=t12;ZTAM_GREG(16,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(24,8,0)=t00*(4096*(groupsz));ZTAM_GREG(6,8,0)=(4096)*t11;ZTAM_GREG(7,8,0)=(t1);ZTAM_GREG(11,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(22,8,0)=t10*(4096);ZTAM_GREG(3,8,0)=((((dycnt2-1)-(0)+(1))/(1))-1);ZTAM_GREG(2,8,0)=((1*(NUM_THREAD_PER_CORE)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(10,8,0)=1023;ZTAM_GREG(21,8,0)=0;ZTAM_GREG(14,8,0)=((((NUM_THREAD_PER_CORE-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=1023;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(5,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1))*(1);ZTAM_GREG(12,8,0)=1023;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(56+(0)*((1*(NUM_THREAD_PER_CORE)*(VECTOR_WIDTH)))+(0)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),(0));}
               }
               if(req->out_interleave==kTensorFormatFlat || req->out_interleave==kTensorFormatFlatAndInterleaved) {
                  // Output in non-interleave format
{{int t00=(0),t01=(1),t02=((group-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((dycnt2-1)),t2=t22,t30=(0),t31=(1),t32=(((groupsz)-1)),t3=t32,t40=(0),t41=(1),t42=(((2)-1)),t4=t42,t50=(0),t51=(1),t52=(((8)-1)),t5=t52;ZTAM_GREG(13,8,0)=(1*((VECTOR_WIDTH-1)+1)*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=(((group-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(23,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1));ZTAM_GREG(0,8,0)=(1*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))*t11;ZTAM_GREG(1,8,0)=(t1);ZTAM_GREG(9,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(20,8,0)=t10*(1*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1));ZTAM_GREG(2,8,0)=(1*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))*t21;ZTAM_GREG(3,8,0)=(t2);ZTAM_GREG(10,8,0)=(((dycnt2-1)+1)-t20)*(1*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(21,8,0)=t20*(1*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1));ZTAM_GREG(16,8,0)=(1*(((2)-1)+1)*(((8)-1)+1))*t31;ZTAM_GREG(17,8,0)=(t3);ZTAM_GREG(18,8,0)=((((groupsz)-1)+1)-t30)*(1*(((2)-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(24,8,0)=t30*(1*(((2)-1)+1)*(((8)-1)+1));ZTAM_GREG(6,8,0)=(1*(((8)-1)+1))*t41;ZTAM_GREG(7,8,0)=(t4);ZTAM_GREG(11,8,0)=((((2)-1)+1)-t40)*(1*(((8)-1)+1))-1;ZTAM_GREG(22,8,0)=t40*(1*(((8)-1)+1));ZTAM_GREG(8,8,0)=((1)*t51);ZTAM_GREG(5,8,0)=(t5);ZTAM_GREG(12,8,0)=((((8)-1)+1)-1-t50);ZTAM_GREG(25,8,0)=t50*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))+t10*(1*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))+t20*(1*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))+t30*(1*(((2)-1)+1)*(((8)-1)+1))+t40*(1*(((8)-1)+1))+t50*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*(t3+1)*(t4+1)*(t5+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(group-1),t0=t02,t10=(0),t11=(1),t12=((groupsz)-1),t1=t12;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(3,8,0)=((((dycnt2-1)-(0)+(1))/(1))-1);ZTAM_GREG(2,8,0)=((1*(2)*(8)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(10,8,0)=1023;ZTAM_GREG(21,8,0)=0;ZTAM_GREG(7,8,0)=(((((2)-1)-(0)+(1))/(1))-1);ZTAM_GREG(6,8,0)=((1*(8)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(11,8,0)=1023;ZTAM_GREG(22,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(12,8,0)=1023;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(1,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(0,8,0)=((1))*(1);ZTAM_GREG(9,8,0)=1023;ZTAM_GREG(20,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(56+(0)*((1*(2)*(8)*(VECTOR_WIDTH)))+(0)*((1*(8)*(VECTOR_WIDTH)))+(0)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1033245|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),((DP_CONDITION_SRAM_FLUSH)|0));}{{int t00=(i),t01=(1),t02=(i+step-1),t0=(t02-t00),t10=(mm),t11=(1),t12=(mm+xy2-1),t1=(t12-t10);ZTAM_GREG(16,8,0)=(1*(topsz))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((req->topcnt)-t00)*(1*(topsz))-1;ZTAM_GREG(24,8,0)=t00*(1*(topsz));ZTAM_GREG(8,8,0)=((1)*t11);ZTAM_GREG(5,8,0)=(t1);ZTAM_GREG(12,8,0)=((topsz)-1-t10);ZTAM_GREG(25,8,0)=t10*(1);int tbar=t00*(1*(topsz))+t10*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->top)>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((group-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((dycnt2-1)),t2=t22,t30=(0),t31=(1),t32=(((groupsz)-1)),t3=t32,t40=(0),t41=(1),t42=(((2)-1)),t4=t42,t50=(0),t51=(1),t52=(((8)-1)),t5=t52;ZTAM_GREG(0,8,0)=(1*((VECTOR_WIDTH-1)+1)*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))*t01;ZTAM_GREG(1,8,0)=(t0);ZTAM_GREG(9,8,0)=(((group-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(20,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1));ZTAM_GREG(2,8,0)=(1*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))*t11;ZTAM_GREG(3,8,0)=(t1);ZTAM_GREG(10,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(21,8,0)=t10*(1*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1));ZTAM_GREG(6,8,0)=(1*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))*t21;ZTAM_GREG(7,8,0)=(t2);ZTAM_GREG(11,8,0)=(((dycnt2-1)+1)-t20)*(1*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(22,8,0)=t20*(1*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1));ZTAM_GREG(13,8,0)=(1*(((2)-1)+1)*(((8)-1)+1))*t31;ZTAM_GREG(14,8,0)=(t3);ZTAM_GREG(15,8,0)=((((groupsz)-1)+1)-t30)*(1*(((2)-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(23,8,0)=t30*(1*(((2)-1)+1)*(((8)-1)+1));ZTAM_GREG(16,8,0)=(1*(((8)-1)+1))*t41;ZTAM_GREG(17,8,0)=(t4);ZTAM_GREG(18,8,0)=((((2)-1)+1)-t40)*(1*(((8)-1)+1))-1;ZTAM_GREG(24,8,0)=t40*(1*(((8)-1)+1));ZTAM_GREG(8,8,0)=((1)*t51);ZTAM_GREG(5,8,0)=(t5);ZTAM_GREG(12,8,0)=((((8)-1)+1)-1-t50);ZTAM_GREG(25,8,0)=t50*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))+t10*(1*((dycnt2-1)+1)*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))+t20*(1*(((groupsz)-1)+1)*(((2)-1)+1)*(((8)-1)+1))+t30*(1*(((2)-1)+1)*(((8)-1)+1))+t40*(1*(((8)-1)+1))+t50*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((topfmt))&1)));;ZTAM_GREG(19,8,0)=(1034269|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(DP_CONDITION_SRAM_FLUSH));}
               }
            } else {
               if(req->out_interleave==kTensorFormatInterleaved || req->out_interleave==kTensorFormatFlatAndInterleaved) {
                  // Output in interleave format
{{int t00=(mm),t01=(1),t02=(mm+xy2-1),t0=(t02-t00),t10=(i),t11=(1),t12=(i+step-1),t1=(t12-t10);ZTAM_GREG(16,8,0)=(1*(req->topcnt))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((topsz)-t00)*(1*(req->topcnt))-1;ZTAM_GREG(24,8,0)=t00*(1*(req->topcnt));ZTAM_GREG(8,8,0)=((1)*t11);ZTAM_GREG(5,8,0)=(t1);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t10);ZTAM_GREG(25,8,0)=t10*(1);int tbar=t00*(1*(req->topcnt))+t10*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->top_interleave)>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(group-1),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((group)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=((((xy2-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=1023;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(5,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1))*(1);ZTAM_GREG(12,8,0)=1023;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(56+(0)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),(0));}
               }
               if(req->out_interleave==kTensorFormatFlat || req->out_interleave==kTensorFormatFlatAndInterleaved) {
                  // Output in non-interleave format
{{int t00=(0),t01=(1),t02=((group-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((xy3/8-1)),t2=t22,t30=(0),t31=(1),t32=(((8)-1)),t3=t32;ZTAM_GREG(16,8,0)=(1*((VECTOR_WIDTH-1)+1)*((xy3/8-1)+1)*(((8)-1)+1))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=(((group-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((xy3/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(24,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((xy3/8-1)+1)*(((8)-1)+1));ZTAM_GREG(6,8,0)=(1*((xy3/8-1)+1)*(((8)-1)+1))*t11;ZTAM_GREG(7,8,0)=(t1);ZTAM_GREG(11,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((xy3/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(22,8,0)=t10*(1*((xy3/8-1)+1)*(((8)-1)+1));ZTAM_GREG(13,8,0)=(1*(((8)-1)+1))*t21;ZTAM_GREG(14,8,0)=(t2);ZTAM_GREG(15,8,0)=(((xy3/8-1)+1)-t20)*(1*(((8)-1)+1))-1;ZTAM_GREG(23,8,0)=t20*(1*(((8)-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((((8)-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((xy3/8-1)+1)*(((8)-1)+1))+t10*(1*((xy3/8-1)+1)*(((8)-1)+1))+t20*(1*(((8)-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*(t3+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(group-1),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((group)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(14,8,0)=((((xy3/8-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=((1*(8)*(VECTOR_WIDTH)))*(1);ZTAM_GREG(15,8,0)=1023;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=((1*(VECTOR_WIDTH)))*(1);ZTAM_GREG(12,8,0)=1023;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(7,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(6,8,0)=((1))*(1);ZTAM_GREG(11,8,0)=1023;ZTAM_GREG(22,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(56+(0)*((1*(8)*(VECTOR_WIDTH)))+(0)*((1*(VECTOR_WIDTH)))+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1033245|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),((DP_CONDITION_SRAM_FLUSH)|0));}{{int t00=(i),t01=(1),t02=(i+step-1),t0=(t02-t00),t10=(mm),t11=(1),t12=(mm+xy3-1),t1=(t12-t10);ZTAM_GREG(16,8,0)=(1*(topsz))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((req->topcnt)-t00)*(1*(topsz))-1;ZTAM_GREG(24,8,0)=t00*(1*(topsz));ZTAM_GREG(8,8,0)=((1)*t11);ZTAM_GREG(5,8,0)=(t1);ZTAM_GREG(12,8,0)=((topsz)-1-t10);ZTAM_GREG(25,8,0)=t10*(1);int tbar=t00*(1*(topsz))+t10*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->top)>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((group-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((xy3/8-1)),t2=t22,t30=(0),t31=(1),t32=(((8)-1)),t3=t32;ZTAM_GREG(6,8,0)=(1*((VECTOR_WIDTH-1)+1)*((xy3/8-1)+1)*(((8)-1)+1))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=(((group-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((xy3/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(22,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((xy3/8-1)+1)*(((8)-1)+1));ZTAM_GREG(13,8,0)=(1*((xy3/8-1)+1)*(((8)-1)+1))*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((xy3/8-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(23,8,0)=t10*(1*((xy3/8-1)+1)*(((8)-1)+1));ZTAM_GREG(16,8,0)=(1*(((8)-1)+1))*t21;ZTAM_GREG(17,8,0)=(t2);ZTAM_GREG(18,8,0)=(((xy3/8-1)+1)-t20)*(1*(((8)-1)+1))-1;ZTAM_GREG(24,8,0)=t20*(1*(((8)-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((((8)-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((xy3/8-1)+1)*(((8)-1)+1))+t10*(1*((xy3/8-1)+1)*(((8)-1)+1))+t20*(1*(((8)-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((topfmt))&1)));;ZTAM_GREG(19,8,0)=(1034269|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(DP_CONDITION_SRAM_FLUSH));}
               }
            }
            mm += dysz*dycnt2;
         }
      }
   }
}

// Perform depth-wise convolution

static void convolution_depthwise(void *_p,int pid) {
   RequestConv *req=(RequestConv *)_p;
   int i,k,r,r2,r3,c2,c;
   int kk;
   int offset,topoffset;
   int index;
   int m,n;
   int x,y;
   int botcnt;
   int topcnt2;
   int coefsz;
   int topcnt;
   int botdim;
   int kz,gkz;
   int rowi;
   int from,to;
   int groupsz,group,step;
   int np;
   int stride_dx,stride_dy;
   uint32_t bot,coef;
   int conv_dx,conv_dy,conv_dy2,conv_dx2;
   int dysz,dycnt,dxcnt;
   int dx;
   int topfmt=UINT8;
   int botfmt=UINT8;
   int biasfmt=INT16;
   int weightfmt=UINT8;
   int f,loop;
   int count,minCount,interation,minInteration;
   int batchcnt,maxgroupsz,mingroup;
   int threadSubBlock;

   np=NUM_PCORE;
   kz=req->ksz*req->ksz;   
   botdim=req->botdim-2*req->pad;
   botcnt=req->botcnt;
   bot=req->bot;
   coef=req->coef;
   coefsz=((ROUND(req->topcnt,VECTOR_WIDTH)>>VECTOR_DEPTH)*kz)*VECTOR_WIDTH; 

   conv_dx=1;
   minCount=0;
   for(dx=1;dx <= NUM_THREAD_PER_CORE;dx++) {
      if((dx*req->stride+req->ksz-req->stride)>CONV_DEPTHWISE_BOT_DX)
         break;
      count = (req->topdim+dx-1)/dx;
      if(count < minCount || dx==1) {
         minCount=count;
         conv_dx=dx;
      }
   }
   if(conv_dx <= (NUM_THREAD_PER_CORE/2))
      conv_dx2=(NUM_THREAD_PER_CORE/2);
   else
      conv_dx2=NUM_THREAD_PER_CORE;
   topcnt=0;
   topoffset=0;
   maxgroupsz=(CONV_DEPTHWISE_BOT_DY-req->ksz+req->stride)/req->stride;
   mingroup=(NUM_PCORE+maxgroupsz-1)/maxgroupsz;
   for(group=NUM_PCORE;group >= mingroup;group=group/2) {

      // pcores are divided into group where each group work on the 
      // same convolution tensor.
      // We want to start with the smallest group so that we can process
      // as many tensors at the same time as we can
      // And the remaining tensors after each pass will be processed in a larger group
      // This ensures maximum usage of computation resources with the least
      // waste...

      topoffset+=topcnt; 
      topcnt=req->topcnt-topoffset;
      if(topcnt<=0)
         break;
      topcnt2=ROUND((topcnt+1)/2,VECTOR_WIDTH);
      batchcnt=group*VECTOR_WIDTH;
      if((group/2)>=mingroup)
         topcnt2=(topcnt2/batchcnt)*batchcnt; // Round down
      else
         topcnt2=((topcnt2+batchcnt-1)/batchcnt)*batchcnt; // Round up
      topcnt2=topcnt2*2;
      if(topcnt2 < topcnt)
         topcnt=topcnt2;
      if(topcnt==0)
         continue;
      groupsz=NUM_PCORE/group;
      dxcnt=NUM_THREAD_PER_CORE/conv_dx;
      if(dxcnt>2) dxcnt=2;
      if((dxcnt*groupsz*req->stride+(req->ksz-req->stride)) > CONV_DEPTHWISE_BOT_DY)
         dxcnt=1;
      dycnt=(req->topdim+groupsz-1)/groupsz;
      dycnt=(dycnt+dxcnt-1)/dxcnt;
      if(dycnt > CONV_DEPTHWISE_Y_DIM)
         dycnt=CONV_DEPTHWISE_Y_DIM;
      while((dycnt*dxcnt*groupsz*req->stride+(req->ksz-req->stride)) > CONV_DEPTHWISE_BOT_DY)
         dycnt--;
      conv_dy2=groupsz;
      conv_dy=conv_dy2*dycnt*dxcnt;
      step=group<<VECTOR_DEPTH;
      gkz=kz*group*VECTOR_WIDTH;
      x=conv_dx*req->stride+req->ksz-req->stride;
      y=conv_dy*req->stride+req->ksz-req->stride;
      dysz=x*conv_dy2*req->stride;
      stride_dy=conv_dy*req->stride;
      stride_dx=conv_dx*req->stride;
      threadSubBlock=(conv_dx2==NUM_THREAD_PER_CORE)?2:dxcnt;
      if(x > CONV_DEPTHWISE_BOT_DX) ztaAbort(0);
      if(y > CONV_DEPTHWISE_BOT_DY) ztaAbort(0);

      // Initialize module...

{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(32);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(req->stride);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(34);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(req->activation_scale);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(35);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(req->bias_scale);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(36);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(x);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

      for(i=0;i < np;i++) {
         index=(i%groupsz);
{{int t00=(i),t01=(1),t02=(i),t0=(t02-t00),t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(33);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(index);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
      }
      if(dxcnt==1) {
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,66,((np)-1),0,0,0,(15),0);
      } else {    
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,86,((np)-1),0,0,0,(15),0);
      }
      ztaTaskYield();

      if(pid==0) {
         from=0;
         to=ROUND((topcnt+1)/2,VECTOR_WIDTH);
      } else {
         from=ROUND((topcnt+1)/2,VECTOR_WIDTH);
         to=topcnt;
      }
      from+=topoffset;
      to+=topoffset;

      f=ztaBuildKernelFunc(1891,np,(dxcnt==1)?conv_dx:NUM_THREAD_PER_CORE/2+conv_dx);

{int t00=(0),t01=(1),t02=((group)-1),t0=t02,t10=(0),t11=(1),t12=(0),t1=t12;ZTAM_GREG(6,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(22,8,0)=t00*(4096*(groupsz));ZTAM_GREG(13,8,0)=(4096)*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(23,8,0)=t10*(4096);ZTAM_GREG(17,8,0)=((((kz-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(8)*(1);ZTAM_GREG(18,8,0)=71;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=71;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(8+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*(((kz-1)-(0)+(1))/(1))*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((1|((weightfmt)<<5))|((((((groupsz)-1))&((1<<(MCAST_WIDTH-1))-1))+(0<<(MCAST_WIDTH-1)))<<14))|((0)<<8)|((0)<<1);}


      if(req->in_interleave) {
{int t00=(0),t01=(1),t02=(group-1),t0=t02,t10=(0),t11=(1),t12=(0),t1=t12;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(7,8,0)=((((x*y-1)-(0)+(1))/(1))-1);ZTAM_GREG(6,8,0)=(8)*(1);ZTAM_GREG(11,8,0)=1279;ZTAM_GREG(22,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=1279;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(80+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*(((x*y-1)-(0)+(1))/(1))*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((1|((botfmt)<<5))|((((((groupsz)-1))&((1<<(MCAST_WIDTH-1))-1))+(0<<(MCAST_WIDTH-1)))<<14))|((0)<<8)|((1)<<1);}
      } else {
{int t00=(0),t01=(1),t02=(group-1),t0=t02,t10=(0),t11=(1),t12=(0),t1=t12;ZTAM_GREG(6,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(22,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(5,8,0)=((((x*y-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(8)*(1);ZTAM_GREG(12,8,0)=1279;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(14,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=(1)*(1);ZTAM_GREG(15,8,0)=1279;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(80+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*(((x*y-1)-(0)+(1))/(1))*(((VECTOR_WIDTH-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((1|((botfmt)<<5))|((((((groupsz)-1))&((1<<(MCAST_WIDTH-1))-1))+(0<<(MCAST_WIDTH-1)))<<14))|((0)<<8)|((1)<<1);}
      }

      for(i=from;i < to;i += step) {
{{int t00=(0),t01=(1),t02=((group)-1),t0=t02,t10=(0),t11=(1),t12=(0),t1=t12;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(1360+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((31|((biasfmt)<<5))|((((((groupsz)-1))&((1<<(MCAST_WIDTH-1))-1))+(0<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+step-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->biasHi)>>((((biasfmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((biasfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=((group)-1),t0=t02,t10=(0),t11=(1),t12=(0),t1=t12;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(4096)+t00*(4096*(groupsz))+(1368+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((31|((biasfmt)<<5))|((((((groupsz)-1))&((1<<(MCAST_WIDTH-1))-1))+(0<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+step-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->biasLo)>>((((biasfmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((biasfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

         rowi=((i>>VECTOR_DEPTH)*kz)*VECTOR_WIDTH;

{int t00=(rowi),t01=(1),t02=(rowi+gkz-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((coefsz)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((coef)>>((((weightfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036289|((weightfmt)<<5))|((0)<<8)|((2)<<1);}
{{ZTAM_GREG(0,13,0)=0;ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_DEST<<1);}{ZTAM_GREG(2,13,0)=0;ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_SRC<<1);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((2)>=0)?1:0,(2)&(3),(0));}

         for(r=0,r2=-req->pad;r < req->topdim;r += conv_dy,r2 += stride_dy) {
            for(c=0,c2=-req->pad;c < req->topdim;c += conv_dx,c2+=stride_dx) {

               if(req->in_interleave) {
{{ZTAM_GREG(1,13,0)=0;ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_DEST<<1);}{int t00=(r2),t01=(1),t02=(r2+y-1),t0=(t02-t00),t10=(c2),t11=(1),t12=(c2+x-1),t1=(t12-t10),t20=(i),t21=(1),t22=(i+group*VECTOR_WIDTH-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(botdim)*(botcnt))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((botdim)-t00)*(1*(botdim)*(botcnt))-1;ZTAM_GREG(23,8,0)=t00*(1*(botdim)*(botcnt));ZTAM_GREG(16,8,0)=(1*(botcnt))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((botdim)-t10)*(1*(botcnt))-1;ZTAM_GREG(24,8,0)=t10*(1*(botcnt));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((botcnt)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(botdim)*(botcnt))+t10*(1*(botcnt))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((bot)>>((((botfmt))&1)));;ZTAM_GREG(28,8,0)=(0);ZTAM_GREG(19,8,0)=(1036317|((botfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((1)>=0)?1:0,(1)&(3),(0));}
               } else {
{{ZTAM_GREG(1,13,0)=0;ZTAM_GREG(19,8,0)=(DP_TEMPLATE_ID_DEST<<1);}{int t00=(i),t01=(1),t02=(i+group*VECTOR_WIDTH-1),t0=(t02-t00),t10=(r2),t11=(1),t12=(r2+y-1),t1=(t12-t10),t20=(c2),t21=(1),t22=(c2+x-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(botdim)*(botdim))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((botcnt)-t00)*(1*(botdim)*(botdim))-1;ZTAM_GREG(23,8,0)=t00*(1*(botdim)*(botdim));ZTAM_GREG(16,8,0)=(1*(botdim))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((botdim)-t10)*(1*(botdim))-1;ZTAM_GREG(24,8,0)=t10*(1*(botdim));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((botdim)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(botdim)*(botdim))+t10*(1*(botdim))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((bot)>>((((botfmt))&1)));;ZTAM_GREG(28,8,0)=(0);ZTAM_GREG(19,8,0)=(1036317|((botfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((1)>=0)?1:0,(1)&(3),(0));}
               }
               dx=req->topdim-c;
               if(dx > conv_dx)
                  dx=conv_dx;

               // Do convolution...

               for(kk=0,offset=0;kk < dycnt;kk++,offset+=dxcnt*dysz) {
                  if((r+kk*conv_dy2*dxcnt) >= req->topdim)
                     break;
ZTAM_GREG(0,23,0)=(kk);
ZTAM_GREG(0,24,0)=(offset);
;ZTAM_GREG(0,5,0)=(f);
               }
               ztaTaskYield();

               // Output results...

{{int t00=(0),t01=(1),t02=((group-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((dycnt-1)),t2=t22,t30=(0),t31=(1),t32=(((groupsz)-1)),t3=t32,t40=(0),t41=(1),t42=((threadSubBlock-1)),t4=t42,t50=(0),t51=(1),t52=((8-1)),t5=t52;ZTAM_GREG(13,8,0)=(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=(((group-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))-1;ZTAM_GREG(23,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1));ZTAM_GREG(0,8,0)=(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))*t11;ZTAM_GREG(1,8,0)=(t1);ZTAM_GREG(9,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))-1;ZTAM_GREG(20,8,0)=t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1));ZTAM_GREG(2,8,0)=(1*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))*t21;ZTAM_GREG(3,8,0)=(t2);ZTAM_GREG(10,8,0)=(((dycnt-1)+1)-t20)*(1*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))-1;ZTAM_GREG(21,8,0)=t20*(1*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1));ZTAM_GREG(16,8,0)=(1*((threadSubBlock-1)+1)*((8-1)+1))*t31;ZTAM_GREG(17,8,0)=(t3);ZTAM_GREG(18,8,0)=((((groupsz)-1)+1)-t30)*(1*((threadSubBlock-1)+1)*((8-1)+1))-1;ZTAM_GREG(24,8,0)=t30*(1*((threadSubBlock-1)+1)*((8-1)+1));ZTAM_GREG(6,8,0)=(1*((8-1)+1))*t41;ZTAM_GREG(7,8,0)=(t4);ZTAM_GREG(11,8,0)=(((threadSubBlock-1)+1)-t40)*(1*((8-1)+1))-1;ZTAM_GREG(22,8,0)=t40*(1*((8-1)+1));ZTAM_GREG(8,8,0)=((1)*t51);ZTAM_GREG(5,8,0)=(t5);ZTAM_GREG(12,8,0)=(((8-1)+1)-1-t50);ZTAM_GREG(25,8,0)=t50*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))+t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))+t20*(1*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))+t30*(1*((threadSubBlock-1)+1)*((8-1)+1))+t40*(1*((8-1)+1))+t50*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*(t3+1)*(t4+1)*(t5+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(group-1),t0=t02,t10=(0),t11=(1),t12=((groupsz)-1),t1=t12,t20=(0),t21=(1),t22=(threadSubBlock-1),t2=t22,t30=(0),t31=(1),t32=(8-1),t3=t32;ZTAM_GREG(13,8,0)=(4096*(groupsz))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((group)-t00)*(4096*(groupsz))-1;ZTAM_GREG(23,8,0)=t00*(4096*(groupsz));ZTAM_GREG(16,8,0)=(4096)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((4096)-t10)*(4096)-1;ZTAM_GREG(24,8,0)=t10*(4096);ZTAM_GREG(6,8,0)=(256*8)*t21;ZTAM_GREG(7,8,0)=(t2);ZTAM_GREG(11,8,0)=((256*8)-t20)*(256*8)-1;ZTAM_GREG(22,8,0)=t20*(256*8);ZTAM_GREG(8,8,0)=(256)*t31;ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((256)-t30)*(256)-1;ZTAM_GREG(25,8,0)=t30*(256);ZTAM_GREG(3,8,0)=((((dycnt-1)-(0)+(1))/(1))-1);ZTAM_GREG(2,8,0)=(8)*(1);ZTAM_GREG(10,8,0)=23;ZTAM_GREG(21,8,0)=0;ZTAM_GREG(1,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(0,8,0)=(1)*(1);ZTAM_GREG(9,8,0)=23;ZTAM_GREG(20,8,0)=0;ZTAM_GREG(4,8,0)=t30*(256)+t20*(256*8)+t10*(4096)+t00*(4096*(groupsz))+(0+(0)*(8)+(0));ZTAM_GREG(19,8,0)=(1033245|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),((DP_CONDITION_SRAM_FLUSH)|0));}{{int t00=(i),t01=(1),t02=(i+step-1),t0=(t02-t00),t10=(r),t11=(1),t12=(r+conv_dy-1),t1=(t12-t10),t20=(c),t21=(1),t22=(c+conv_dx2-1),t2=(t22-t20);ZTAM_GREG(13,8,0)=(1*(req->topdim)*(req->topdim))*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((req->topcnt)-t00)*(1*(req->topdim)*(req->topdim))-1;ZTAM_GREG(23,8,0)=t00*(1*(req->topdim)*(req->topdim));ZTAM_GREG(16,8,0)=(1*(req->topdim))*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((req->topdim)-t10)*(1*(req->topdim))-1;ZTAM_GREG(24,8,0)=t10*(1*(req->topdim));ZTAM_GREG(8,8,0)=((1)*t21);ZTAM_GREG(5,8,0)=(t2);ZTAM_GREG(12,8,0)=((req->topdim)-1-t20);ZTAM_GREG(25,8,0)=t20*(1);int tbar=t00*(1*(req->topdim)*(req->topdim))+t10*(1*(req->topdim))+t20*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->top)>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((group-1)),t0=t02,t10=(0),t11=(1),t12=((VECTOR_WIDTH-1)),t1=t12,t20=(0),t21=(1),t22=((dycnt-1)),t2=t22,t30=(0),t31=(1),t32=(((groupsz)-1)),t3=t32,t40=(0),t41=(1),t42=((threadSubBlock-1)),t4=t42,t50=(0),t51=(1),t52=((8-1)),t5=t52;ZTAM_GREG(0,8,0)=(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))*t01;ZTAM_GREG(1,8,0)=(t0);ZTAM_GREG(9,8,0)=(((group-1)+1)-t00)*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))-1;ZTAM_GREG(20,8,0)=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1));ZTAM_GREG(2,8,0)=(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))*t11;ZTAM_GREG(3,8,0)=(t1);ZTAM_GREG(10,8,0)=(((VECTOR_WIDTH-1)+1)-t10)*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))-1;ZTAM_GREG(21,8,0)=t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1));ZTAM_GREG(6,8,0)=(1*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))*t21;ZTAM_GREG(7,8,0)=(t2);ZTAM_GREG(11,8,0)=(((dycnt-1)+1)-t20)*(1*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))-1;ZTAM_GREG(22,8,0)=t20*(1*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1));ZTAM_GREG(13,8,0)=(1*((threadSubBlock-1)+1)*((8-1)+1))*t31;ZTAM_GREG(14,8,0)=(t3);ZTAM_GREG(15,8,0)=((((groupsz)-1)+1)-t30)*(1*((threadSubBlock-1)+1)*((8-1)+1))-1;ZTAM_GREG(23,8,0)=t30*(1*((threadSubBlock-1)+1)*((8-1)+1));ZTAM_GREG(16,8,0)=(1*((8-1)+1))*t41;ZTAM_GREG(17,8,0)=(t4);ZTAM_GREG(18,8,0)=(((threadSubBlock-1)+1)-t40)*(1*((8-1)+1))-1;ZTAM_GREG(24,8,0)=t40*(1*((8-1)+1));ZTAM_GREG(8,8,0)=((1)*t51);ZTAM_GREG(5,8,0)=(t5);ZTAM_GREG(12,8,0)=(((8-1)+1)-1-t50);ZTAM_GREG(25,8,0)=t50*(1);int tbar=t00*(1*((VECTOR_WIDTH-1)+1)*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))+t10*(1*((dycnt-1)+1)*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))+t20*(1*(((groupsz)-1)+1)*((threadSubBlock-1)+1)*((8-1)+1))+t30*(1*((threadSubBlock-1)+1)*((8-1)+1))+t40*(1*((8-1)+1))+t50*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((topfmt))&1)));;ZTAM_GREG(19,8,0)=(1034269|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(DP_CONDITION_SRAM_FLUSH));}
            }
         }      
      }
   }
}

typedef struct {
   int size;
   uint32_t input[2];
   uint32_t output;
   uint32_t stream;
} RequestAdd;

// Perform add layer 

static void do_add_process(void *_p,int pid)
{
   RequestAdd *req=(RequestAdd *)_p;
   int i,np,step,step2,from,to;
   int fmt=UINT8;
   np=NUM_PCORE;

   step=NUM_PCORE*NUM_THREAD_PER_CORE*VECTOR_WIDTH;
   step2=step;
   if(pid==0) {
      from=0;
      to=ROUND(req->size/2,step);
   } else {
      from=ROUND(req->size/2,step);
      to=req->size;
   }
   for(i=from;i < to;i+=step) { 
{{int t00=(0),t01=(1),t02=((np)-1),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=7;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(0);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((7)+1));ZTAM_GREG(19,8,0)=(1032223|((fmt)<<5))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+step2-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->size)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(31,8,0)=(((req->size)>>((((fmt))&1)))-tbar);;ZTAM_GREG(4,8,0)=tbar+((req->input[0])>>((((fmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((1)>=0)?1:0,(1)&(3),(0));}
{{int t00=(0),t01=(1),t02=((np)-1),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=7;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(8);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((7)+1));ZTAM_GREG(19,8,0)=(1032223|((fmt)<<5))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+step2-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->size)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(31,8,0)=(((req->size)>>((((fmt))&1)))-tbar);;ZTAM_GREG(4,8,0)=tbar+((req->input[1])>>((((fmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((2)>=0)?1:0,(2)&(3),(0));}
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,272,((np)-1),0,0,0,(15),0);
      ztaTaskYield();
{{int t00=(i),t01=(1),t02=(i+step2-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->size)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(31,8,0)=(((req->size)>>((((fmt))&1)))-tbar);;ZTAM_GREG(4,8,0)=tbar+((req->output)>>((((fmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((fmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((np)-1),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=7;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(16);ZTAM_GREG(19,8,0)=(1032221|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),(0));}
   }
}

// Process add request

void kernel_add_exe(
   unsigned int _req_id,
   int _size,
   unsigned int _input_0,
   unsigned int _input_1,
   unsigned int _output,
   unsigned int _stream
)
{
   RequestAdd req;
   
   ztaInitPcore(zta_pcore_img);
   ztaInitStream(_stream);
   
   req.size=_size;
   req.input[0]=_input_0;
   req.input[1]=_input_1;
   req.output=_output;
   req.stream=_stream;
   
   ztaDualHartExecute(do_add_process,&req);

   ztaJobDone(_req_id);
}

// Process convolution request

void kernel_convolution_exe(
   unsigned int _req_id,
   unsigned int _coef,
   unsigned int _biasHi,
   unsigned int _biasLo,
   unsigned int _bot,
   unsigned int _top,
   unsigned int _top_interleave,
   int _ksz,
   int _topcnt,
   int _topdim,
   int _botcnt,
   int _botdim,
   int _input_offset,
   int _activation_scale,
   unsigned int _stream,
   int _group,
   int _stride,
   int _pad,
   int _conv_dx,
   int _dycnt,
   int _groupsz,
   int _in_interleave,
   int _out_interleave
)
{
   RequestConv req;
   int depth_fifo;

   ztaInitPcore(zta_pcore_img);
   ztaInitStream(_stream);
   
   req.coef=_coef;
   req.biasHi=_biasHi;
   req.biasLo=_biasLo;
   req.bot=_bot;
   req.top=_top;
   req.top_interleave=_top_interleave;
   req.ksz=_ksz;
   req.topcnt=_topcnt;
   req.topdim=_topdim;
   req.botcnt=_botcnt;
   req.botdim=_botdim;
   req.input_offset=_input_offset;
   req.activation_scale=_activation_scale;
   req.stream=_stream;
   req.group=_group;
   req.stride=_stride;
   req.pad=_pad;
   req.conv_dx=_conv_dx;
   req.dycnt=_dycnt;
   req.groupsz=_groupsz;
   req.in_interleave=_in_interleave;
   req.out_interleave=_out_interleave;

   if(req.ksz==1)
   {
      ztaDualHartExecute(convolution_1x1,&req);
   }
   else
   {
      ztaDualHartExecute(convolution_3x3,&req);
   }
   ztaJobDone(_req_id);
}


// Process depth_wise convolution request

void kernel_convolution_depthwise_exe(
   unsigned int _req_id,
   unsigned int _coef,
   unsigned int _biasHi,
   unsigned int _biasLo,
   unsigned int _bot,
   unsigned int _top,
   unsigned int _top_interleave,
   int _ksz,
   int _topcnt,
   int _topdim,
   int _botcnt,
   int _botdim,
   int _input_offset,
   int _activation_scale,
   unsigned int _stream,
   int _group,
   int _stride,
   int _pad,
   int _conv_dx,
   int _dycnt,
   int _groupsz,
   int _in_interleave,
   int _out_interleave
)
{
   RequestConv req;
   int depth_fifo;
   
   ztaInitPcore(zta_pcore_img);
   ztaInitStream(_stream);
   
   req.coef=_coef;
   req.biasHi=_biasHi;
   req.biasLo=_biasLo;
   req.bot=_bot;
   req.top=_top;
   req.top_interleave=_top_interleave;
   req.ksz=_ksz;
   req.topcnt=_topcnt;
   req.topdim=_topdim;
   req.botcnt=_botcnt;
   req.botdim=_botdim;
   req.input_offset=_input_offset;
   req.activation_scale=_activation_scale;
   req.stream=_stream;
   req.group=_group;
   req.stride=_stride;
   req.pad=_pad;
   req.conv_dx=_conv_dx;
   req.dycnt=_dycnt;
   req.groupsz=_groupsz;
   req.in_interleave=_in_interleave;
   req.out_interleave=_out_interleave;
   
   ztaDualHartExecute(convolution_depthwise,&req);

   ztaJobDone(_req_id);
}

