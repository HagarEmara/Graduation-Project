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
#include "../../../../SW/base/ztalib.h"
#include "../../../../SW/src/soc.h"
#include "test.p.img"

#define BUFSZ (16*8*NUM_PCORE*2)

static volatile uint16_t inbuf[BUFSZ];
static volatile uint16_t outbuf[BUFSZ];

typedef struct {
   uint32_t in_p;
   uint32_t out_p;
   int len;
} REQUEST;


// Each thread is doing half the tensor
// First thread is processing the top half of tensor
// Second thread is processing the bottom half of tensor

static void test(void *_p,int pid) {
   REQUEST *req=(REQUEST *)_p;
   uint32_t from,to;

   if(pid==0) {
      from=0;
      to=req->len/2-1;
   } else {
      from=req->len/2;
      to=req->len-1;
   }

{{int t00=(0),t01=(1),t02=(NUM_PCORE-1),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=((((7)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(0+(0));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*(((7)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{int t00=(from),t01=(1),t02=(to),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((67108864)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->in_p)>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1036317|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,0,((NUM_PCORE)-1),0,0,0,(15),0);

   ztaTaskYield();

{{int t00=(from),t01=(1),t02=(to),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((67108864)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->out_p)>>(((INT16)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|(INT16<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(NUM_PCORE-1),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=((((7)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(8+(0));ZTAM_GREG(19,8,0)=(1032221|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
}

//
// This is a simple test
// It add 1 to every elements of a tensor
//

void kernel_test_exe() {
   uint32_t resp;
   REQUEST req; 
   int i;

   ztaInitPcore(zta_pcore_img);

   req.in_p=(uint32_t)&inbuf[0];
   req.out_p=(uint32_t)&outbuf[0];
   req.len = BUFSZ;
   
   for(i=0;i < req.len;i++)
      inbuf[i]=(i&0xFF);

   FLUSH_DATA_CACHE();

   ztaDualHartExecute(test,&req);

   ztaJobDone(0);

   // Wait for response....
   for(;;) {
      if(ztaReadResponse(&resp))
         break;
   }   

   for(i=0;i < req.len;i++) {
      if(outbuf[i] != ((i&0xFF)+1)) {
         for(;;) {
            APB[0]=0xffffffff;
         }
      }
   }
}
