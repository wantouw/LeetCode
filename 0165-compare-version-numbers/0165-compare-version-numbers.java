class Solution {
    public int compareVersion(String version1, String version2) {
            String[] version11 = version1.split("\\.");
        String[] version22 = version2.split("\\.");
        int maxSize = Math.max(version11.length, version22.length);
    //    System.out.println("version11: " +  version11);
    //    System.out.println("version22: " +  version22.toString());
        for(int i = 0 ; i < maxSize ; i++) {
            int v1 = 0;
            int v2 = 0;
            if(i < version11.length) {
                v1 = Integer.parseInt(version11[i]);
            }
            if(i < version22.length) {
                v2 = Integer.parseInt(version22[i]);
            }
        //      System.out.println("v1: " + v1 + ", v2: " + v2);
            if(v1 > v2){
                return 1;
            } else if(v1 < v2) {
                return -1;
            }
        }
        return 0;

    }
}