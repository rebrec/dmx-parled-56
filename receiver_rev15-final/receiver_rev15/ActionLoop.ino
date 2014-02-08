void action() { 
  float coef=1;
  dmx_rouge = dmxvalue[0];
  dmx_vert = dmxvalue[1];
  dmx_bleu = dmxvalue[2];
  dmx_dim_gnl = dmxvalue[3];
  dmx_strobe = dmxvalue[4];
  
  coef = dmx_dim_gnl / 255;
  
  analogWrite(PIN_ROUGE, dmx_rouge * dmx_dim_gnl / 255);
  analogWrite(PIN_VERT, dmx_vert * dmx_dim_gnl / 255);
  analogWrite(PIN_BLEU, dmx_bleu * dmx_dim_gnl / 255);
  if (dmx_strobe > 0)
  {
    delay(strobe_on_time); 
    analogWrite(PIN_ROUGE, 0);
    analogWrite(PIN_VERT, 0);
    analogWrite(PIN_BLEU, 0);
    delay(dmx_strobe+10); 

  }
  return;  //go back to loop()
} //end action() loop

