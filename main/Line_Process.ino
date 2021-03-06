float GetError() { //Get the "error" in the moving direction
  static int prev_error = 0;
  switch (HighSignalCount()) {
    case 0: {
        if(turn < 0)
        {
          prev_left = prev_right = 0;
          turn = 0;
          prev_error = 10;
          return 10;
        }
        if(turn > 0)
        {
          prev_left = prev_right = 0;
          turn = 0;
          prev_error = -10;
          return -10;
        }
        if (prev_error == 0) {
          return 0;
        } else if (prev_error >= 8) {
          prev_error = 10;
          return 10;
        } else if (prev_error <= -8) {
          prev_error = -10;
          return -10;
        }
        return prev_error;
        break;
    }
    case 1: {
        if(Line[0] == true) {
          prev_error = -10;
          prev_left = prev_right = 0;
          return -10; 
        }
        if(Line[1] == true) {
          prev_error = -8;
          prev_left = prev_right = 1;
          return -8;
        }
        if(Line[2] == true) {
          prev_error = -6;
          prev_left = prev_right = 2;
          return -6;
        }
        if(Line[3] == true) {
          prev_error = -4;
          prev_left = prev_right = 3;
          return -4;
        }
        if(Line[4] == true) {
          prev_error = -2;
          prev_left = prev_right = 4;
          return -2;
        }
        if(Line[5] == true) {
          prev_error = 2;
          prev_left = prev_right = 5;
          return 2;
        }
        if(Line[6] == true) {
          prev_error = 4;
          prev_left = prev_right = 6;
          return 4;
        }
        if(Line[7] == true) {
          prev_error = 6;
          prev_left = prev_right = 7;
          return 6;
        }
        if(Line[8] == true) {
          prev_error = 8;
          prev_left = prev_right = 8;
          return 8;
        }
        if (Line[9] == true ) {
          prev_error = 10;
          prev_left = prev_right = 9;
          return 10;
        }
        break;
      }
    case 2: {
  
      if ((Line[0]==1) && (Line[1]==1)) {
        prev_error = -10;
        prev_left = 1;
        prev_right = 0;
        return -10;
      }
    
      if ((Line[1]==1) && (Line[2]==1)) {
        prev_error = -8;
        prev_left = 2;
        prev_right = 1;
        return -8;
      }
    
      if ((Line[2]==1) && (Line[3]==1)) {
        prev_error = -6;
        prev_left = 3;
        prev_right = 2;
        return -6;
      }
    
      if ((Line[3]==1) && (Line[4]==1)) {
        prev_error = -4;
        prev_left = 4;
        prev_right = 3;
        return -4;
      }
    
      if ((Line[4]==1) && (Line[5]==1)) {
        prev_error = 0;
        prev_left = 5;
        prev_right = 4;
        return 0;
      }
    
      if ((Line[5]==1) && (Line[6]==1)) {
        prev_error = 4;
        prev_left = 6;
        prev_right = 5;
        return 4;
      }
    
      if ((Line[6]==1) && (Line[7]==1)) {
        prev_error = 6;
        prev_left = 7;
        prev_right = 6;
        return 6;
      }
    
      if ((Line[7]==1) && (Line[8]==1)) {
        prev_error = 8;
        prev_left = 8;
        prev_right = 7;
        return 8;
      }
    
      if ((Line[8]==1) && (Line[9]==1)) {
        prev_error = 10;
        prev_left = 9;
        prev_right = 8;
        return 10;
      }
      return prev_error;
      break;
      }
    case 3: {
      if ( (Line[0]==1) && (Line[1]==1) && (Line[2]==1)) {prev_error = -20; return -10;}
      if ( (Line[1]==1) && (Line[2]==1) && (Line[3]==1)) {prev_error = -8; return -8;}
      if ( (Line[2]==1) && (Line[3]==1) && (Line[4]==1)) {prev_error = -6; return -6;}
      if ( (Line[3]==1) && (Line[4]==1) && (Line[5]==1)) {prev_error = -4; return -4;}
      if ( (Line[4]==1) && (Line[5]==1) && (Line[6]==1)) {prev_error = 4; return 4;}
      if ( (Line[5]==1) && (Line[6]==1) && (Line[7]==1)) {prev_error = 6; return 6;}
      if ( (Line[6]==1) && (Line[7]==1) && (Line[8]==1)) {prev_error = 8; return 8;}
      if ( (Line[7]==1) && (Line[8]==1) && (Line[9]==1)) {prev_error = 20; return 10;}
      for(int i = 0; i < 10; i++)
      {
        if(Line[i] == 1 && i > prev_left + 1)
        {
          turn = -1;
          break;
        }
        if(Line[i] == 1 && i < prev_right - 1)
        {
          turn = 1;
          break;
        }
      }
      return prev_error;
      break;
    }
    case 4: {
      if ((Line[0]==1) && (Line[1]==1) && (Line[2]==1) && (Line[3]==1)) {prev_error = -10; return -10;}
      if ((Line[1]==1) && (Line[2]==1) && (Line[3]==1) && (Line[4]==1)) {prev_error = -8; return -8;}
      if ((Line[2]==1) && (Line[3]==1) && (Line[4]==1) && (Line[5]==1)) {prev_error = -6; return -6;}
      if ((Line[3]==1) && (Line[4]==1) && (Line[5]==1) && (Line[6]==1)) {prev_error = 0; return 0;}
      if ((Line[4]==1) && (Line[5]==1) && (Line[6]==1) && (Line[7]==1)) {prev_error = 6; return 6;}
      if ((Line[5]==1) && (Line[6]==1) && (Line[7]==1) && (Line[8]==1)) {prev_error = 8; return 8;}
      if ((Line[6]==1) && (Line[7]==1) && (Line[8]==1) && (Line[9]==1)) {prev_error = 10; return 10;}
      for(int i = 0; i < 10; i++)
      {
        if(Line[i] == 1 && i > prev_left + 1)
        {
          turn = -1;
          break;
        }
        if(Line[i] == 1 && i < prev_right - 1)
        {
          turn = 1;
          break;
        }
      }
      return prev_error;
      break;
    }
    case 5: {
      if (Line[0]==1 && Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1) { prev_error = -10; return -10; }
      if (Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1) { prev_error = -8; return -8; }
      if (Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1) { prev_error = -6; return -6; }
      if (Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1) { prev_error = 6; return 6; }
      if (Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1) { prev_error = 8; return 8; }
      if (Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1 && Line[9]==1) { prev_error = 10; return 10; }
      return prev_error;
      break;
    }
    case 6: {
      if (Line[0]==1 && Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1) { prev_error = -10; return -10; }
      if (Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1) { prev_error = -8; return -8; }
      if (Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1) { prev_error = 0; return 0; }
      if (Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1) { prev_error = 8; return 8; }
      if (Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1 && Line[9]==1) { prev_error = 10; return 10; }
      return prev_error;
      break;
    }
    case 7: {
      if (Line[0]==1 && Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1) { prev_error = -10; return -10; }
      if (Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1) { prev_error = -8; return -8; }
      if (Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1) { prev_error = 8; return 8; }
      if (Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1 && Line[9]==1) { prev_error = 10; return 10; }
      return prev_error;
      break;
    }
    case 8: {
      if (Line[0]==1 && Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1) { prev_error = 10; return 10; }
      if (Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1) { prev_error = 0; return 0; }
      if (Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1 && Line[9]==1) { prev_error = -10; return -10; }
      return prev_error;
      break;
    }
    case 9: {
      if (Line[0]==1 && Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1) { prev_error = 10; return 10; }
      if (Line[1]==1 && Line[2]==1 && Line[3]==1 && Line[4]==1 && Line[5]==1 && Line[6]==1 && Line[7]==1 && Line[8]==1 && Line[9]==1) { prev_error = -10; return -10; }
      return prev_error;
      break;
    }
    case 10:
    {
      prev_error = 0;
      return 0;
    }
    default: {
      return 0;
      break;
    }
  }
}

int HighSignalCount() { //Count the high signal that speed up the GetError function
  int count = 0;
  for (int i = 0; i < 10; i++) {
    if (Line[i] == true) {
      count++;
    }
  }
  return count;
}
void GetSensorStatus() { //Get all the sensor status
  for (int i = 0; i < 10; i++) {
    Line[i] = ReadLine(i);
  }
}

bool ReadLine(int index) { //Get the sensor status for each sensor
  int temp = analogRead(Sensors[index]);
  if (temp <= Sensor_HIGH) {
    return true;
  }
  else {
    return false;
  }
}
