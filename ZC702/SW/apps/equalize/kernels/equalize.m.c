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
#include "equalize.h"
#include "equalize.h"
#include "equalize.p.img"

// Perform histogram equalization

typedef struct {
   uint32_t input;
   uint32_t output;
   uint32_t output2;
   int nchannels;
   uint32_t equalize;
   int w;
   int h;
   struct {
      int channel;
      int extra_zero[2];
   } ws;
} Request;

extern void mycallback(int);

static void equalize(void *_p,int pid) {
   Request *req=(Request *)_p;
   int x,y;
   int step,step_x,step_y;
   int dx,dy;
   uint32_t input,output2,p;
   int i,j,count,extra_zero;
   int np,nt;
   int len;
   int src_w,src_h;

   input=req->input+req->w*req->h*req->ws.channel;
   output2=req->output2+req->w*req->h*req->ws.channel;
   np=NUM_PCORE;
   nt=NUM_THREAD_PER_CORE;
   step_x = kHistogramInSize*nt;
   step_y = np;
   dx=req->w;
   dy=req->h;
   src_w=req->w;
   src_h=req->h;

   dx=dx*dy;
   dy=1;
   src_w=src_w*src_h;
   src_h=1;
   step_x=step_x*step_y;
   step_y=1;

   // Split the job in the X direction
   if(pid==0) {
      dx=dx/2;
      src_w=src_w/2;
   } else {
      input=input+dx/2;
      output2=output2+dx/2;
      dx=dx-dx/2;
      src_w=src_w-src_w/2;
   }

   count=1000/kHistogramInSize;

   i=0;
   j=0;
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,0,((np)-1),0,0,0,((nt)-1),0);
   ztaTaskYield();

   for(y=0;y < dy;y+=step_y) {
      for(x=0;x < dx;x += step_x) {
{{int t00=(0),t01=(1),t02=((np)-1),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((kHistogramInSize*nt-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=127;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(1032+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((kHistogramInSize*nt-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(UINT8<<5))|((0)<<8);}{int t00=(x),t01=(1),t02=(x+step_x-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((src_w)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((input)>>(((UINT8)&1)));;ZTAM_GREG(19,8,0)=(1036317|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

         if(req->equalize) {
{{int t00=(x),t01=(1),t02=(x+step_x-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((src_w)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((output2)>>(((UINT8)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|(UINT8<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((np)-1),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((kHistogramInSize*nt-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=127;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(1032+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),(1));}
         } else {
{{int t00=(x),t01=(1),t02=(x+step_x-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((src_w)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((output2)>>(((UINT8)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|(UINT8<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((np)-1),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((kHistogramInSize*nt-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=127;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(1032+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(1));}
         }

;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,102,((np)-1),0,0,0,((nt)-1),0);

         ztaTaskYield();

         i++;
         j+=(step_x*step_y);
         if(i >= count) {
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,30,((np)-1),0,0,0,((nt)-1),0);
            ztaTaskYield();
            i=0;
         }
      }
   }

;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,30,((np)-1),0,0,0,((nt)-1),0);

   ztaTaskYield();

ZTAM_GREG(0,23,0)=(nt);

   // Summarize results among the threads...
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,58,((np)-1),0,1,0,((kHistogramBinSize)-1),0);
   ztaTaskYield();

   // Save results to SCRATCH...
   len=np*kHistogramBinSize*VECTOR_WIDTH;
   p=(pid==0)?0:len*2*2;
{{int t00=(0),t01=(1),t02=(len-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((len)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((p)>>(((INT16)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|(INT16<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(np-1),t0=t02;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(17,8,0)=((((kHistogramBinSize-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(8)*(1);ZTAM_GREG(18,8,0)=511;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
   p += len*2;
{{int t00=(0),t01=(1),t02=(len-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((len)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((p)>>(((INT16)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|(INT16<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(np-1),t0=t02;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(17,8,0)=((((kHistogramBinSize-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(8)*(1);ZTAM_GREG(18,8,0)=511;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(520+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

   req->ws.extra_zero[pid]=j-dx*dy;
}

// Aggregate the results from all the cores from both process 1 & 2

static void equalize_final(Request *req) {
   uint32_t p;
   int np,len,extra_zero;

   np=NUM_PCORE;
   len=np*kHistogramBinSize*VECTOR_WIDTH;
   p=0;
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(17,8,0)=((((kHistogramBinSize*np-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(8)*(1);ZTAM_GREG(18,8,0)=511;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((kHistogramBinSize*np-1)-(0)+(1))/(1))*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(len-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((len)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((p)>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
   p += len*2;
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(17,8,0)=((((kHistogramBinSize*np-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(8)*(1);ZTAM_GREG(18,8,0)=511;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(520+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((kHistogramBinSize*np-1)-(0)+(1))/(1))*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(len-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((len)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((p)>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
   p += len*2;
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(17,8,0)=((((kHistogramBinSize*2*np-1)-(kHistogramBinSize*np)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(8)*(1);ZTAM_GREG(18,8,0)=511;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(kHistogramBinSize*np)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((kHistogramBinSize*2*np-1)-(kHistogramBinSize*np)+(1))/(1))*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(len-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((len)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((p)>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
   p += len*2;
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(17,8,0)=((((kHistogramBinSize*2*np-1)-(kHistogramBinSize*np)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(8)*(1);ZTAM_GREG(18,8,0)=511;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(520+(kHistogramBinSize*np)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((kHistogramBinSize*2*np-1)-(kHistogramBinSize*np)+(1))/(1))*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(len-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((len)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((p)>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

   if((2*np) > NUM_THREAD_PER_CORE)
      ztaAbort(0);

ZTAM_GREG(0,23,0)=(2*np);
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,58,((1)-1),0,1,0,((kHistogramBinSize)-1),0);

   extra_zero=req->ws.extra_zero[0]+req->ws.extra_zero[1];

{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(520+(kHistogramBinSize)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(extra_zero/1000);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(kHistogramBinSize)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(extra_zero%1000);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,88,((1)-1),0,0,0,((1)-1),0);

   p=req->output+req->ws.channel*(kHistogramBinSize*VECTOR_WIDTH)*2*2;
{{int t00=(0),t01=(1),t02=(((kHistogramBinSize*VECTOR_WIDTH)-1)),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((kHistogramBinSize*VECTOR_WIDTH)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((p)>>(((INT16)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|(INT16<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(17,8,0)=((((kHistogramBinSize-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(8)*(1);ZTAM_GREG(18,8,0)=511;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(520+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
   p+=kHistogramBinSize*VECTOR_WIDTH*2;
{{int t00=(0),t01=(1),t02=(((kHistogramBinSize*VECTOR_WIDTH)-1)),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((kHistogramBinSize*VECTOR_WIDTH)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((p)>>(((INT16)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|(INT16<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(17,8,0)=((((kHistogramBinSize-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(8)*(1);ZTAM_GREG(18,8,0)=511;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=511;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0)*(8)+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
}

// Process request from host to do equalization/histogram

void kernel_equalize_exe(
   unsigned int _req_id,
   unsigned int _input,
   unsigned int _output,
   unsigned int _output2,
   int _nchannels,
   unsigned int _equalize,
   int _w,
   int _h
   ) 
{
   Request req;
   int i;
   
   ztaInitPcore(zta_pcore_img);
   ztaInitStream(_equalize);
      
   req.input=_input;
   req.output=_output;
   req.output2=_output2;
   req.nchannels=_nchannels;
   req.equalize=_equalize;
   req.w=_w;
   req.h=_h;
   
   for(i=0;i < req.nchannels;i++) {
      req.ws.channel=i;
      ztaDualHartExecute(equalize,&req);
      equalize_final(&req);
   }
   ztaJobDone(_req_id);
}

