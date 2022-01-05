class Solution {
    public List<List<String>> Anagrams(String[] string_list) {
        // Code here
        List<List<String>> result = new ArrayList<List<String>>();
    	List<String> keyList = new ArrayList<>();// just to maintain order
    	Map<String, List<String>> map = new HashMap<>();
    	for(String str: string_list) {
    		char chars[] = str.toCharArray();
    		Arrays.sort(chars);
    		String key = String.valueOf(chars);
    // 		System.out.println(key);
    		// if that key present then get that list and append new element to it
			List<String> strList = new ArrayList<>();
    		if(map.containsKey(key)) {
    			strList = map.get(key);
    		}
    		// add key to list if not present - to maintain order of insertion
    		if(!keyList.contains(key)) {
    			keyList.add(key);
    		}
    		// add the word to correct group
			strList.add(str);
    		map.put(key, strList);
    	}
    	// add list to result from map as per key order
    	for(String key : keyList) {
    		result.add(map.get(key));
    	}
    	return result;
    }
}
